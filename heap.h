#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  void trickleUp(size_t idx); 
  void heapify(size_t idx); 

  std::vector<T> items;
  int m; // for m-ary
  PComparator comparator; // for heap order

};

// Add implementation of member functions here
//constructor
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c): m(m), comparator(c)
{
}

//destructor
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{
}

// empty
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return items.empty(); 
}

// size
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return items.size(); 
}

// push
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  items.push_back(item); 
  trickleUp(items.size() -1); 
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(size_t idx)
{
  size_t parent = (idx -1)/ m; // 0 index 
  while(idx >0 && comparator(items[idx], items[parent])){
    std::swap(items[idx], items[parent]); 
    idx = parent; 
    parent = (idx -1)/m; 
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(size_t idx)
{
  size_t best = idx; // assume curr is best 
  for(int i = 1; i <= m; ++i){ // loop through all children
    size_t child = m*idx +i;  // find index 
    if(child <items.size() && comparator(items[child], items[best])){
      best = child; // update best 
    }
  }
  if(best != idx){ // if child has higher priority 
    std::swap(items[idx], items[best]);  // swap curr with best
    heapify(best); 
  }
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
      throw std::underflow_error("Empty heap, Can't access top.");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return items[0]; 

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty heap, Can't access top.");

  }
  // swap, pop, then heapify 
  std::swap(items[0], items.back()); 
  items.pop_back(); 
  if(!empty()){
    heapify(0); 
  }

}



#endif

