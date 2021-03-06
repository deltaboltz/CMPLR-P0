#include <iostream>
#include <string>
#include <fstream>

#include "node.h" //inOrder() , preOrder() , postOrder()
#include "tree.h" //Prototypes for function definitions in this class

static node<std::string> root;

void buildTree(std::istream& in)
{
  std::string word;

  while(in >> word)
  {
    root.insert(word.substr(0,1), word);
  }

}

void printInorder(std::string base)
{
  std::ofstream ofs;
  std::string a = base + ".inorder";

  ofs.open(a.c_str());
  root.inOrder(ofs);
  ofs.close();

}

void printPreorder(std::string base)
{
  std::ofstream ofs;
  std::string a = base + ".preorder";

  ofs.open(a.c_str());
  root.preOrder(ofs);
  ofs.close();

}

void printPostorder(std::string base)
{
  std::ofstream ofs;
  std::string a = base + ".postorder";

  ofs.open(a.c_str());
  root.postOrder(ofs);
  ofs.close();

}
