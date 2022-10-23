#include <map>
template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
	: m_valBegin(val)
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign( K const& keyBegin, K const& keyEnd, V const& val ) 
  {
    if(keyEnd < keyBegin)
    {
      return;
    }

    // m_valBegin value that is associated with all keys less than the first key in m_map
    if(val == m_valBegin)
    {
      if(m_map.size() == 0)
      {
        return;
      }
      else
      {
        auto it = m_map.begin();
        if((keyBegin < it->first) || (!(it->first < keyBegin))) // <= check!!
        {
          return;
        }
      }
    }

    //As map is empty and value is not same as m_valBegin() just accept the value
    if(m_map.size() == 0)
    {
      //m_map[keyBegin] = val;
      m_map.insert({keyBegin, val});
      return;
    }

    auto end = m_map.end();
    if((--end)->first < keyBegin)
    {
      m_map[keyBegin] = val;
      return;
    }

    auto prev = m_map.lower_bound(keyBegin);  // either the iterator pointing to keyBegin or next value of keyBegin
    auto next = m_map.lower_bound(keyEnd);  // either the iterator pointing to keyEnd or next value of keyEnd
    if(prev == m_map.end())
    {
      //m_map[keyBegin] = val;
      m_map.insert({keyBegin, val});
      return;
    }
    else if(next == m_map.end())
    {
      //last entry in the map!!
      if((--prev)->second == val)
      { //As consecutive entried cannot be same!! simply return!
        return;
      }

      //m_map[keyBegin] = val;
      m_map.insert({keyBegin, val});
      { //Remove overlapping elements
        auto current = m_map.upper_bound(keyBegin);
        while(current != m_map.end())
        {
          auto currentNext = current;
          currentNext++;

          m_map.erase(current);
          current = currentNext;
        }
      }
      return;
    }
    else if(next == prev)
    {
      if(((--prev)->second == val) || (next->second == val))
      {
        return;
      }

      //m_map[keyBegin] = val;
      m_map.insert({keyBegin, val});
      return;
    }

    //validate for range!! if there is no conflicts!, just assign the value for that range!
    if(((--prev)->second == val) || (next->second == val))
    {
      return;
    }

    //m_map[keyBegin] = val;
    m_map.insert({keyBegin, val});
    { //Remove overlapping elements
      auto current = m_map.upper_bound(keyBegin);
      while(current != next)
      {
        auto currentNext = current;
        currentNext++;

        m_map.erase(current);
        current = currentNext;
      }
    }
	}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.

class keyType_t
{
  int key;
  public:
  keyType_t(int k) : key(k) {}
  keyType_t(const keyType_t& other)
  {
    key = other.key;
  }

  void operator=(const keyType_t& other)
  {
    key = other.key;
  }

  bool operator<(const keyType_t& other) const
  {
    return (key < other.key);
  }
};

class valueType_t
{
  char val;
  public:
  //valueType_t() {}
  valueType_t(char c) : val(c) {}

  valueType_t(const valueType_t& other)
  {
    val = other.val;
  }

  void operator=(const valueType_t& other)
  {
    val = other.val;
  }

  bool operator==(const valueType_t& other) const
  {
    return val == other.val;
  }
};

int main()
{
  valueType_t v('A');
  interval_map<keyType_t, valueType_t> m(v);

  {
    keyType_t kb(1);
    keyType_t ke(3);

    m.assign(kb, ke, v);  //fail
  }

  //interval_map<int, char> m('A');
  // m.assign(1, 3, 'A');  //fail
  // m.assign(1, 3, 'B');  //Succeed
  // m.assign(3, 6, 'A');  //Succeed
  // m.assign(11, 11, 'B');  //Succeed
  // m.assign(1,2,'B'); // fail
  // m.assign(6,8,'B');  // fail
  // m.assign(3,8,'B');  // fail
  // m.assign(2,8,'B');  // fail
  // m.assign(3,8,'D'); //Success
  // //m.assign(2,30, 'F');  //Success
  // m.assign(20,30,'E');  //Success
  // m.assign(2,15,'G');  //Success
  return 0;
}