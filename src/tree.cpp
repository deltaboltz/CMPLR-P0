#include <iostream>
#include <string>
#include <fstream>

#include "node.h"
#include "tree.h"

static node<std::string> root;

void buildBST(std::istream& in)
{
  std::string word;

  while(in >> word)
  {
    root.insert(word.substr(0,1), word);
  }

}

void printIn(std::string base)
{
  std::ofstream ofs;
  std::string a = base + ".inorder";

  ofs.open(a.c_str());
  root.inOrder(ofs);
  ofs.close();
  
}

void printPre(std::string base)
{
  std::ofstream ofs;
  std::string a = base + ".preorder";

  ofs.open(a.c_str());
  root.preOrder(ofs);
  ofs.close();

}

void printPost(std::string base)
{
  std::ofstream ofs;
  std::string a = base + ".postorder";

  ofs.open(a.c_str());
  root.postOrder(ofs);
  ofs.close();

}
