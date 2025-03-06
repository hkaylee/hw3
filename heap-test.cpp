#include <iostream>
#include <vector>
#include "heap.h"

using namespace std; 

struct MaxComparator {
  bool operator()(const int& a, const int& b) const {
    return a>b;
  }
};

int main(){
  Heap<int> minHeap; 

  minHeap.push(40); 
  minHeap.push(20); 
  minHeap.push(15); 
  minHeap.push(13); 
  minHeap.push(50); 

  cout << "top: " << minHeap.top()<< endl; 

  minHeap.pop(); 
  cout << "top after pop: " << minHeap.top()<< endl;

  Heap<int, MaxComparator> maxHeap; 

  maxHeap.push(40);
  maxHeap.push(20);
  maxHeap.push(15);
  maxHeap.push(13);
  maxHeap.push(50);

  cout << "top: " << maxHeap.top()<< endl; 

  maxHeap.pop(); 
  cout << "top after pop: " << maxHeap.top()<< endl;
}