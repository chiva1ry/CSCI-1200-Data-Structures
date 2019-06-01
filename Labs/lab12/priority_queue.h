#ifndef priority_queue_h_
#define priority_queue_h_

#include <iostream>
#include <vector>
#include <cassert>


template <class T>
class priority_queue {
private:
  std::vector<T> m_heap;

public:
  priority_queue() {}

  priority_queue( std::vector<T> const& values )
  {
      
      for (int i = 0; i < values.size(); i++) {
          m_heap.push_back(values[i]);
      }
      
      for (int i = (m_heap.size() - 1) / 2; i >= 0 ; i--)
          percolate_down(i);
      
      
  }

  const T& top() const 
  {
    assert( !m_heap.empty() );
    return m_heap[0]; 
  }

  void push( const T& entry )
  {
      m_heap.push_back(entry);
      
      for (int i = m_heap.size() - 1; i >= 0;) {
          if (m_heap[i] < m_heap[(i - 1) / 2]) {
              std::swap(m_heap[i], m_heap[(i - 1) / 2]);
              i = (i - 1) / 2;
          } else {
              break;
          }
      }
      
  }
    
    

  void pop() 
  {
    assert( !m_heap.empty() );
    
      T temp = m_heap[m_heap.size() - 1];
      m_heap[0] = temp;
      m_heap.pop_back();
      
      
      percolate_down(0);
    
    
  }
    
void percolate_down(int i) {
    
    int temp;
    
    while (2 * i + 1 < m_heap.size()) {
        
        if (2 * i + 2 < m_heap.size() && m_heap[2 * i + 2] < m_heap[2 * i + 1]) {
            temp = 2 * i + 2;
        } else {
            temp = 2 * i + 1;
        }
        if (m_heap[temp] < m_heap[i]) {
            std::swap(m_heap[i], m_heap[temp]);
            i = temp;
            
        } else {
            break;
        }
    }
}

  int size() { return m_heap.size(); }
  bool empty() { return m_heap.empty(); }


  //  The following three functions are used for debugging.

  //  Check to see that internally the heap property is realized.
  bool check_heap( )
  {
    return this->check_heap( this->m_heap );
  }

  //  Check an external vector to see that the heap property is realized.
  bool check_heap( const std::vector<T>& heap )
  {
      
      bool check = true;
      
      for (int i = 0; i < heap.size(); i++) {
          if(2 * i + 1 < heap.size()) {
              if (heap[2 * i + 1] <heap[i]) {
                  check = false;
              }
          }
          
          if(2 * i + 2 < heap.size()) {
              if (heap[2 * i + 2] < heap[i]) {
                  check = false;
              }
          }
      }
      
      
      return check;
  }

  //  A utility to print the contents of the heap.  Use it for debugging.
  void print_heap( std::ostream & ostr )
  {
    for ( unsigned int i=0; i<m_heap.size(); ++i )
      ostr << i << ": " << m_heap[i] << std::endl;
  }
  
};

template <class T>
void nm_percolate_up(std::vector<T> &v, int i, int j) {
    
    while(2 * i + 1 < v.size()){
        T temp_val;
        int temp_int;
        
        if(2 * i + 2 < v.size() && v[2 * i + 2] < v[2 * i + 1]){
            temp_val = v[2 * i + 2];
            temp_int = 2 * i + 2;
        }
        
        else{
            temp_val = v[2 * i + 1];
            temp_int = 2 * i + 1;
        }
        
        if(temp_val < v[i]){
            v[temp_int] = v[i];
            v[i] = temp_val;
            i = temp_int;
        }
        
        else
            i++;
    }
}

template <class T>
void nm_percolate_down(std::vector<T> &v, int i, int j) {
    
    while(2 * i + 1 < v.size() - j){
        T temp_val;
        int temp_int;
        
        if(2 * i + 2 < v.size() - j && v[2 * i + 2] < v[2 * i + 1]){
            temp_val = v[2 * i + 2];
            temp_int = 2 * i + 2;
        }
        
        else{
            temp_val = v[2 * i + 1];
            temp_int = 2 * i + 1;
        }
        
        if(temp_val < v[i]){
            v[temp_int] = v[i];
            v[i] = temp_val;
            i = temp_int;
        }
        
        else
            break;
    }
}

template <class T>
void heap_sort( std::vector<T> & v )
{
    
    for(unsigned int j = 0; j < v.size() / 2; j++){
        
        nm_percolate_up(v, 0, j);
        
    }
    
    for(unsigned int j = 1; j < v.size(); j++){
        
        T temp1 = v[0];
        T temp2 = v[v.size() - j];
        v[0] = temp2;
        v[v.size() - j] = temp1;
        
        nm_percolate_down(v, 0, j);
        
        
    }
    
    for(unsigned int i = 0; i < v.size() / 2; i++){
        T orig = v[i];
        v[i] = v[v.size() - 1 - i];
        v[v.size() - 1 - i] = orig;

    }
}

#endif
