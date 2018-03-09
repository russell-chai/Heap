/*
Russell Chai
3/1/18
This program creates a max heap of integers, and outputs a visual of the heap and also returns the ordered list
*/
#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>

using namespace std;

//sort the heap so that every parent is greater than each of the children node
int sort(int heap[128], int size) {
  int changed = 0;
  for (int a = size / 2; a > 0; a--) {
    int left = heap[a * 2];
    int right = heap[a * 2 + 1];
    if (heap[a] < left || heap[a] < right) {
      changed++;
      if (left > right) {
	heap[a * 2] = heap[a];
	heap[a] = left;
      }
      else {
        heap[a * 2 + 1] = heap[a];
	heap[a] = right;
      }
    }
  }
  return changed;
}

//printing the visual of the tree using recursion
void print(int heap[128], int index, int tabs) {
  //if has no children, print out the value
  if (index * 2 < 128 && heap[index * 2] == 0 && index * 2 + 1 < 128 && heap[index * 2 + 1] == 0) {
    if (heap[index] == 0) {
      cout << endl;
      return;
    }
    int temp = tabs;
    while (temp != 0) {
      cout << "\t";
      temp--;
    }
    cout << heap[index] << endl;
     
    return;
  }
  //print right part of tree
  print(heap, index * 2 + 1, tabs + 1);
  //print parent node
  int temp = tabs;
  while (temp != 0) {
    cout << "\t";
    temp--;
  }
  cout << heap[index] << endl;
  //print left part of tree
  print(heap, index * 2, tabs + 1);
}
int main() {

  char isFile;
  
  cout << "Are you inputting from a file (y/n)" << endl;

  cin >> isFile;
  cin.ignore();

  int heap[128]; //left branch is index * 2 and right branch is index * 2 + 1
  for (int a = 0; a < 128; a++) {
    heap[a] = 0;
  }
  int size = 0;
  //getting input from file
  if (isFile == 'y') {
    cout << "enter file name" << endl;
    char *fileName = new char(200);
    cin.getline(fileName, 200);

    ifstream fin(fileName);
    
    int number;
    fin >> number;
    fin.ignore();
    size++;
    int index = 1;
    while (!fin.eof()) { //kermit
      heap[index] = number;
      fin >> number;
      fin.ignore();
      size++;
      index++;
    }
  }
  //getting input from typing
  else {
    int index = 1;
    while (true) {
      int number;
      cout << "enter a number" << endl;
      cin >> number;
      size++;
      heap[index] = number;
      index++;
      cout << "continue entering numbers? (y/n)" << endl;
      char character;
      cin >> character;
      if (character == 'n') {
	break;
      }
    }
  }
  //print out what user inputed
  cout << "entered:" << endl;
  for (int a = 1; a <= size; a++) {
    cout << heap[a] << " ";
  }
  cout << endl;
  //sorting the heap
  while (true) {
    int changed = sort(heap, size);
    if (changed == 0) {
      break;
    }
  }

  //printing the visual of the tree
  cout << "visual of tree (sideways)" << endl;
  print(heap, 1, 0);

  //printing out the numbers but ordered
  cout << "ordered list" << endl;
  while (size != 0) { //outputs top node and replaces it with the last node
    cout << heap[1] << " ";
    heap[1] = heap[size];
    heap[size] = 0;
    size--;
    while (true) {
      int changed = sort(heap, size);
      if (changed == 0) {
	break;
      }
    }
  }
}
