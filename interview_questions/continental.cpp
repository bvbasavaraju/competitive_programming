#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  bool sort_type = true; // false - Descending
  {
    vector<int> v = {12, 43, 1, 3, 7, 26};

    for(int n : v)
    {
      std::cout << n << " ";
    }

    std::cout << endl;
    sort(v.begin(), v.end(), [sort_type](const int p1, const int p2) -> bool 
      { 
        if(!sort_type)
        {
          return (p1 > p2); 
        }
        else
        {
          return (p2 > p1); 
        }
      });

    for(int n : v)
    {
      std::cout << n << " ";
    }
    std::cout << endl;
  }

  return 0;
}

bool data_written = false;

void WriteComplete(void)
{
  data_written = true;
}

void ReadComplete(void)
{
  data_written = false;
}

class ReadClass_t
{
  uint32_t ReadAccess(void)
  {
    //while(true)
    {
      if(data_written)
      {
        //lock here;
        std::cout << data << endl;
        //ReadComplete();
        postmsg(writing);
      }
    }
  }
}

class WriteClass_t
{
  // void run()
  // {
  //   message;
  // }
  void WriteAccess(uint32_t data_to_write)
  {
    //while(true)
    {
      if(!data_written)
      {
        //lock here;
        data = data_to_write;
        postmsg(reading);
      }
    }
  }
}

class DataClass_t
{
  accessData();
};

int main()
{
  while(true)
  {
    ThreadPool_t()  //- thead1, thread2
  }
}