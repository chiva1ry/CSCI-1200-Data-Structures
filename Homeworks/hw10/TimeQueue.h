#ifndef __TIMEQ_H_
#define __TIMEQ_H_
//You can change/add to these #includes
#include "Job.h"
#include <ctime>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

typedef int tq_hook; //Used to point to a location in the heap, fill in the "???"

//Forward declaration of Job class, do not remove this line, do not change.
class Job;

//Promise to declare stream output operator for internal vector heap representation
std::ostream& operator<<(std::ostream& out, const std::vector<Job*>& heap);

class TimeQueue{

//////////FILL THIS IN///////////
public:
    // initializer
    TimeQueue() { }
    
    // adds to the vector
    void push(Job* job) {
        heap.push_back(job);
        
        percolate_up(heap.size() - 1);
    }
    
    // removes the last element
    Job* pop() {
        Job* temp = heap[heap.size() - 1];
        heap[0] = temp;
        heap.pop_back();
        
//        percolate_down(0);
        return heap[0];
    }
    
    // prints the vector
    void printHeap(std::ofstream& outfile) {
        outfile << "UQ " << heap.size() << " jobs:" << std::endl;
        for(int i = 0; i < heap.size(); i++) {
            outfile << "\t" << heap[i];
        }
    }
    
    // removes at a specific index
    void remove_from_index(tq_hook urgent_hook) { }
    
    //  returns the first value in the list
    Job* top() {return heap[0];}
    
    // helps in the push function
    void percolate_up(int i);
    // helps in the pop function
    void percolate_down(int i);
    
private:
    std::vector<Job*> heap;
};

#endif
