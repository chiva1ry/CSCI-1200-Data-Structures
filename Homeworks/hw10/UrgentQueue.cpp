//
//  UrgentQueue.cpp
//  hw10
//
//  Created by Sriyuth Sagi on 4/25/18.
//  Copyright © 2018 Sriyuth Sagi. All rights reserved.
//

#include "UrgentQueue.h"
#include <stdio.h>





// function to percolate up during push
void UrgentQueue::percolate_up(int i) {
    
    // loops until the break statement
    while (true) {
        
        // finds parent to a position
        int parent = (i - 1) / 2;
        
        // exits if this is the beginning of the vector
        if (i == 0) {
            return;
        }
        
        // swaps the position if the parent is greater than that position
        if (heap[i]->getPriority() < heap[parent]->getPriority()) {
            
            // swaps their positions
            std::swap(heap[i], heap[parent]);
            
            // reassigns the time values at these jobs
            heap[i]->time_hook = i;
            heap[parent]->time_hook = parent;
            
            // iterates to the next position
            i = parent;
            
        } else { // breaks the loop
            break;
        }
    }
}



void UrgentQueue::percolate_down(int i) {
    
    // loops until the break statement
    while (true) {
        
        // finds variables to determin children to a position
        int left_child = 2 * i + 1;
        int right_child = 2 * i + 2;
        int child;
        
        // exits if this is past the end of the vector
        if (left_child >= heap.size() && right_child >= heap.size()) {
            break;
        }
        
        
        // decides which child value to be used
        if (right_child >= heap.size() && heap[right_child]->getPriority() < heap[left_child]->getPriority()) {
            child = left_child;
        } else {
            child = right_child;
        }
        
        // swaps the position if the parent is greater than that position
        if (heap[i]->getPriority() > heap[child]->getPriority()) {
            
            // swaps their positions
            std::swap(heap[i], heap[child]);
            
            // reassigns the time values at these jobs
            heap[i]->time_hook = i;
            heap[child]->time_hook = child;
            
            // iterates to the next position
            i = child;
            
        } else { // breaks the loop
            break;
        }
    }
}
