#include <iostream>
#include <string>
using namespace std;

string LetterChanges(string str)
{
  int length = str.length();
  for (uint32_t i = 0; i < length; i++)
  {
    uint8_t strChar = str[i];
    if ((strChar >= 'a' && strChar <= 'z') || (strChar >= 'A' && strChar <= 'Z'))
    {
      if (strChar == 'z')
      {
        strChar = 'a';
      }
      else if (strChar == 'Z')
      {
        strChar = 'A';
      }
      else
      {
        strChar++;
      }
    }

    switch (strChar)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      strChar -= 32; // difference between small case and upper case letters
      break;

    default:
      break;
    }

    str[i] = strChar;
  }

  return str;
}

int main()
{
  string str;
  cin >> str;
  cout << LetterChanges(str);
  return 0;
}