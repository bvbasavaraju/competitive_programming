#include <iostream>

using namespace std;

class LinkedList_t
{
  private:
    int nodeVal;
    LinkedList_t* next;

  public:
    LinkedList_t(int val)
    {
      nodeVal = val;
      next = nullptr;
    }

    LinkedList_t(int val, LinkedList_t* next_)
    {
      nodeVal = val;
      next = next_;
    }

    int NodeValue(void) const
    {
      return nodeVal;
    }

    LinkedList_t*& Next(void)
    {
      return next;
    }

    LinkedList_t* NextTemp(void)
    {
      return next;
    }
};

/*
  1 2 3 4 5 6 7 8 9 10

  2 1 4 3 6 5 8 7 10 9
*/

void Swap2Nodes(LinkedList_t* node, LinkedList_t* prev)
{
  if(node == nullptr || node->Next() == nullptr)
  {
    return;
  }

  if(prev == nullptr)
  {
    prev = node->Next();
  }
  else
  {
    prev->Next() = node->NextTemp();
  }

  LinkedList_t* future_ = node->NextTemp()->NextTemp();
  node->Next()->Next() = node;
  node->Next() = future_;
}

void PrintList(LinkedList_t* node)
{
  while(node != nullptr)
  {
    std::cout << node->NodeValue() << std::endl;
    node = node->NextTemp();
  }
}

int main()
{
  LinkedList_t* node = new LinkedList_t(1);
  LinkedList_t* head = node;

  for(int i = 2; i<= 10; ++i)
  {
    LinkedList_t* list_ = new LinkedList_t(i);
    if(list_ == nullptr)
    {
      exit(-1);
    }
    node->Next() = list_;
    node = node->NextTemp();
  }

  PrintList(head);
  node = head;
  bool assignHead = true;
  LinkedList_t* prev = nullptr;
  while(node != nullptr && node->NextTemp() != nullptr)
  {
    Swap2Nodes(node, prev);
    if(assignHead)
    {
      head = prev;
      assignHead = false;
    }
    node = node->NextTemp()->NextTemp();
  }

  std::cout << std::endl << std::endl;
  PrintList(head);

  return 0;
}

/*
[Abhishek, Abhijit, Atom, Atomic, Morning]

-> sort => nlogn ==> names = [Abhijit, Abhishek, Atom, Atomic, Morning]

-> unordered_set<string> hash;
-> vector<string> keys(l); = {"Abh", "Abh", "At", "At", "M"}
  int keyCount= 0;
  int i = 0;
  for()
  {
    keys[i] = names[i]
    hash.insert(keys[i]);
    if(i > 1)
    {

    }
  }
*/