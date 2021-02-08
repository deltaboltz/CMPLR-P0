/*
* Created By : Connor Schultz
* Date Created : 2/3/2021
* Last Date Edited : 2/8/2021
*/
#include <iostream>
#include <string>
#include <fstream>

#include "tree.h" //buildTree() , printInorder(), printPreorder(), printPostorder()

using namespace std;
int main(int argc, char* argv[])
{
  std::string base = "output";

  if (argc == 1) //No filename given at all, read from keyboard input until CTRL+D is pressed
  {
    buildTree(cin);
  }
  else if (argc == 2) //Filename is given, build the tree from already typed words until EOF is reached
  {
    std::string fext, filename(""), filearg(argv[1]);
    int len = filearg.length();

    if (len > 4)
    {
      fext = filearg.substr(len-7, len); //check to see if we have the proper file extension
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
      base = filearg.substr(0, len-7); //Set the file output names to be the filename of the input
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
