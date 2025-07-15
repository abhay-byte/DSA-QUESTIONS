#include <iostream>
using namespace std;

class Solution
{
public:
  bool isValid(string word)
  {
    int charCnt = 0;
    bool containsCharDigits = false;
    bool containsVowel = false;
    bool containsConsonent = false;

    for (int ch : word)
    {
      if ((ch >= 97 && ch < 123) || (ch >= 65 && ch < 91))
      {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
          containsVowel = true;
        }
        else
        {
          containsConsonent = true;
        }
        charCnt++;
      }
      else if (ch >= 48 && ch < 58)
      {
        charCnt++;
      }
      else
      {
        return false;
      }
    }

    if (charCnt >= 3 && containsVowel && containsConsonent)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

int main()
{
  Solution obj;
  cout << obj.isValid("Ya$");
}