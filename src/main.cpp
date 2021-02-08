/*
* Created By : Connor Schultz
* Date Created : 2/3/2021
* Last Date Edited : 2/8/2021
*/
#include <iostream>
#include <string>
#include <fstream>
#include "tree.h" //
using namespace std;
int main(int argc, char* argv[])
{
  std::string base = "output";

  if (argc == 1)
  {
    buildTree(cin);
  }
  else if (argc != 1)
  {
    std::string fext, filename(""), filearg(argv[1]);
    int len = filearg.length();


    if (len > 4)
    {
      fext = filearg.substr(len-7, len);
      if (fext == ".sp2021")
      {
          filename = filearg;
      }
    }

    if (filename == "")
    {
        filename = filearg + ".sp2021";
    }

    std::ifstream fs(filename.c_str());
    if (fs)
    {
      base = filearg.substr(0, len-7);
      buildTree(fs);
    }
    else
    {
      cout << "The file '" << filename << "' cannot be opened. Terminating.\n";
      return 2;
    }
  }
  else
  {
    cout << "An incorrect number of arguments was provided. Terminating.\n";
    return 1;
  }

  printInorder(base);
  printPreorder(base);
  printPostorder(base);

  return 0;
}
