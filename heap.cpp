#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>

using namespace std;

int sort(int heap[128]) {
  int changed = 0;
  for (int a = size / 2; a > 0; a--) {
    int left = heap[a * 2]
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

void print(int heap[128], int index, int tabs) {
  if (index * 2 < 128 && heap[index * 2] == 0 && index * 2 + 1 < 128 && heap[index * 2 + 1] == 0) {
    int temp = tabs;
    while (temp != 0) {
      cout << "\t";
      temp--;
    }
    cout << heap[index] << endl;
    return;
  }
  print(heap, index * 2 + 1, tabs + 1);
  int temp = tabs;
  while (temp != 0) {
    cout << "\t";
    temp--;
  }
  cout << heap[index] << endl;
  print(heap, index * 2, tabs + 1);
}
int main() {

  char isFile;
  
  cout << "Are you inputting from a file (y/n)" << endl;

  cin >> isFile;
  cin.ignore();

  int heap[128];
  for (int a = 0; a < 128; a++) {
    heap[a] = 0;
  }
  int size = 0;
  if (isFile == 'y') {
    char *fileName = new char(200);
    cin.getline(fileName, 200);

    ifstream fin(fileName);
    
    int number;
    fin >> number;
    fin.ignore();
    size++;
    int index = 1;
    while (!fin.eof()) {
      heap[index] = number;
      fin >> number;
      fin.ignore();
      size++;
      index++;
    }
  }
  else {
    int index = 1;
    while (true) {
      int number;
      cout << "enter a number" << endl;
      cin >> number;
      cout << number << " " << index << endl;
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
  cout << "entered:" << endl;
  for (int a = 1; a <= size; a++) {
    cout << heap[a] << " ";
  }
  cout << endl;
  while (true) {
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
    if (changed == 0) {
      break;
    }
  }
  cout << "tree is sideways" << endl;
  print(heap, 1, 0);
  
}
