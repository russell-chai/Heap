/*
This program constructs a red black tree
Author: Russell Chai
*/
#include "node.h"
#include "tree.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main() {
 
  tree* list = new tree();//tree

  while (true) {
    cout << "input file name" << endl;

    char* fileName = new char(50);
    cin.getline(fileName, 50);

    ifstream fin(fileName);

    int current = 0;
    while(!fin.eof()) {
      char digit;
      fin >> digit;
      if (digit == ',') {
	cout << "inserting " << current << endl;
	cout << "tree is sideways" << endl;
	list->insert(current, list->getHead());
	list->print(list->getHead(), 0);
	current = 0;
      }
      else {
	current *= 10;
	current += (digit - '0');
      }
    }
    cout << "inserting " << current << endl;
    cout << "tree is sideways" << endl;
    list->insert(current, list->getHead());
    list->print(list->getHead(), 0);
  }
}
