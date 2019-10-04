#include "PQ.h"
#include "heap.h"

int main() {
  PQ_maxHeap myheap;

  myheap.insert(7);
  myheap.insert(1);
  myheap.insert(3);
  myheap.insert(5);
  myheap.insert(8);
  myheap.insert(6);
  myheap.insert(2);
  myheap.insert(4);

  
  myheap.showheap();
  cout << myheap.peek() << endl << endl;

  myheap.getMax();

  myheap.showheap();
  cout << myheap.peek() << endl << endl;

  heap theCustomheap(7);

  theCustomheap.insert(7);
  theCustomheap.insert(1);
  theCustomheap.insert(3);
  theCustomheap.insert(5);
  theCustomheap.insert(8);
  theCustomheap.insert(6);
  theCustomheap.insert(2);
  theCustomheap.insert(4);
  
  theCustomheap.showheap();

}