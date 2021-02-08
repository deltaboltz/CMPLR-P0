#ifndef NODE_H
#define NODE_H
#include <set>

template <class T>
class node
{
private:
  node<T>* lchild;
  node<T>* rchild;
  T keyT;

  std::set<T> dataT;

  bool set;
  void preHelp(std::ostream& out, std::string indent);
  void inHelp(std::ostream& out, std::string indent);
  void postHelp(std::ostream& out, std::string indent);

public:
  node<T> ();
  std::string toString();
  void insert(T key, T item);

  void preOrder();
  void preOrder(std::ostream& out);

  void inOrder();
  void inOrder(std::ostream& out);

  void postOrder();
  void postOrder(std::ostream& out);
};

template <class T>
void node<T>::preHelp(std::ostream& out, std::string indent)
{
  std::string newindent("      ");
  newindent += indent;

  out << indent << toString();

  if(lchild != NULL)
  {
    lchild -> preHelp(out, newindent);
  }

  if(rchild != NULL)
  {
    rchild -> preHelp(out, newindent);
  }
}

template <class T>
void node<T>::inHelp(std::ostream& out, std::string indent)
{
  std::string newindent("      ");
  newindent += indent;

  if (lchild != NULL)
  {
    lchild -> inHelp(out, newindent);
  }

  out << indent << toString();

  if (rchild != NULL)
  {
    rchild -> inHelp(out, newindent);
  }
}

template <class T>
void node<T>::postHelp(std::ostream& out, std::string indent)
{
  std::string newindent("      ");
  newindent += indent;
  if (lchild != NULL)
  {
    lchild -> postHelp(out, newindent);
  }

  if (rchild != NULL)
  {
    rchild -> postHelp(out, newindent);
  }

  out << indent << toString();
}


template <class T>
node<T>::node()
{
  set = false;
}

template <class T>
std::string node<T>::toString()
{
  typename std::set<T>::iterator itr = dataT.begin();

  std::string out("");

  if(set)
  {
    out += keyT + "      " + *itr;
    itr++;

    for(; itr != dataT.end(); ++itr)
    {
      out += "      " + *itr;
    }

    out += "\n";

  }

  return out;
}

template <class T>
void node<T>::insert(T key, T item)
{
  if(set)
  {
    //if the key matches a already made key then add item to the set
    if(keyT == key)
    {
      dataT.insert(item);
    }


    //else we will recursively call to create new nodes until we reach the node we need
    else if(keyT > key)
    {
      if(lchild == NULL)
      {
        lchild = new node();
      }

      lchild -> insert(key, item);
    }

    else
    {
      if(rchild == NULL)
      {
        rchild = new node();
      }
      rchild -> insert(key, item);
    }
  }

  else //only occurs when data is first being put into the node, then we set the insert key (keyT)
  {
    set = true;
    keyT = key;
    dataT.insert(item);
  }
}

// Each traversal has a standard cout stream as well as an
// overloaded function for ostream
template <class T>
void node<T>::preOrder()
{
  preHelp(std::cout, "");
}

template <class T>
void node<T>::preOrder(std::ostream& out)
{
  preHelp(out, "");
}

template <class T>
void node<T>::inOrder()
{
  inHelp(std::cout, "");
}

template <class T>
void node<T>::inOrder(std::ostream& out)
{
  inHelp(out, "");
}

template <class T>
void node<T>::postOrder()
{
  postHelp(std::cout, "");
}

template <class T>
void node<T>::postOrder(std::ostream& out)
{
  postHelp(out, "");
}

#endif
