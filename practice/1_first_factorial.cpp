#include <iostream>
#include <string>

using namespace std;

int FirstFactorial(int num)
{
  if (1 == num)
  {
    return 1;
  }
  return num * FirstFactorial(num - 1);
}

int main()
{
  int num = 1;
  cin >> num;

  // keep this function call here
  cout << FirstFactorial(num);
  return 0;
}
