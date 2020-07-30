#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
  string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
  string key{"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

  string input;
  cout << "Enter your secret Message: ";
  getline(cin, input);

  vector<int> arr{};
  vector<char> str_arr{};

  for (size_t i = 0; i < input.length(); i++)
  {
    for (size_t j = 0; j < alphabet.length(); j++)
    {
      if (input.at(i) == alphabet.at(j))
      {
        arr.push_back(j);
      }
    }
    if (isblank(input.at(i)))
    {
      arr.push_back(' ');
    }
  }

  for (auto a : arr)
  {
    if (a == 32)
    { //32 is ascii for space
      str_arr.push_back(' ');
      continue;
    }
    for (size_t i = 0; i < key.length(); i++)
    {
      if (i == a)
      {
        str_arr.push_back(key.at(i));
      }
    }
  }

  for (auto s : str_arr)
  {
    cout << s;
  }

  cout << endl;

  return 0;
}