#include <iostream>
#include <string>
using namespace std;

string FirstReverse(string str)
{
  string retVal = str;

  int pos1 = 0;
  int pos2 = retVal.length() - 1;

  while (pos1 <= pos2)
  {
    swap(retVal[pos1], retVal[pos2]);
    pos1++;
    pos2--;
  }

  return retVal;
}

int main()
{
  string str;
  cin >> str;
  // keep this function call here
  cout << FirstReverse(str);
  return 0;
}