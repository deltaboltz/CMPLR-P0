#include <iostream>
#include <string>
#include <fstream>
#include "tree.h"
using namespace std;
int main(int argc, char* argv[])
{
  std::string base;

  if (argc == 1)
  {
    buildBST(cin);
    base = "output";
  }
  else if (argc == 2)
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
      buildBST(fs);
      base = filename.substr(0, len-7);
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


  printIn(base);
  printPre(base);
  printPost(base);

  return 0;
}
