/* ASSUMPTIONS:
1. When a node must be split and has an odd number of keys, the extra key will go to the new right-hand node.
2. There will never be a duplicate key passed to insert.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#ifndef DS_BPLUSTREE
#define DS_BPLUSTREE

///////////////////////////////////////////////////////////////////////////////
//DO NOT CHANGE THIS CODE
///////////////////////////////////////////////////////////////////////////////

//Do not implement the class here, this is a forward declaration. Implement at
//the bottom of the .h file
template <class T> class BPlusTree; 

template <class T>
class BPlusTreeNode{
public:
	BPlusTreeNode() : parent(NULL) {};
	bool is_leaf();
	bool contains(const T& key);

	//For grading only. This is bad practice to have, because
	//it exposes a private member variable.
	BPlusTreeNode* get_parent() { return parent; } 

	//We need this to let BPlusTree access private members
	friend class BPlusTree<T>; 
private:
	bool contains(const T& key,std::size_t low,std::size_t high);
	std::vector<T> keys;
	std::vector<BPlusTreeNode*> children;
	BPlusTreeNode* parent;
};

template <class T>
bool BPlusTreeNode<T>::is_leaf(){
	for(unsigned int i=0; i<children.size(); i++){
		if(children[i]){
			return false;
		}
	}
	return true;
}

template <class T>
bool BPlusTreeNode<T>::contains(const T& key){
	return contains(key,0,keys.size()-1);
}

//Private method takes advantage of the fact keys are sorted
template <class T>
bool BPlusTreeNode<T>::contains(const T& key,std::size_t low,std::size_t high){
	if(low>high){
		return false;
	}
	if(low==high){
		return key == keys[low];
	}
	std::size_t mid = (low+high)/2;
	if(key<=keys[mid]){
		return contains(key,0,mid);
	}
	else{
		return contains(key,mid+1,high);
	}
}

///////////////////////////////////////////////////////////////////////////////////////
//Your BPlusTree implementation goes below this point.
///////////////////////////////////////////////////////////////////////////////////////




template <class T>
class BPlusTree{
public:
    // basic initializer
    BPlusTree(int def_b) {b = def_b;}
    
    // copy initializer
    BPlusTree(BPlusTree<T>& copy_tree);
    void copy_helper(BPlusTreeNode<T>* node, BPlusTreeNode<T>* copy_node);
    
    // destructor
    ~BPlusTree() {delete_helper(root);}
    void delete_helper(BPlusTreeNode<T>* position);
    
    // accessor for b
    int get_b() {return b;}
    
    // insert to the tree
    void insert(const T& value);
    void seperate(const T& value, BPlusTreeNode<T>* insert_position);
    
    // find position in the tree
    BPlusTreeNode<T>* find(const T& value) const;
    
    // print the tree sideways
    void print_sideways(ofstream& outfile) const;
    
    // print the tree breadth
    void print_BFS(ofstream& outfile) const;
    
private:
    
    // node of top position in the tree
    BPlusTreeNode<T>* root = NULL;
    
    // index for maximum branches
    int b;
    
};




// copy initialization
template <class T>
BPlusTree<T>::BPlusTree(BPlusTree<T>& copy_tree) {
    
    // set b
    b = copy_tree.get_b();
    
    // copy all nodes from the other tree
    root = new BPlusTreeNode<T>;
    copy_helper(root, copy_tree.root);
}




// recursive helper function for copy
template <class T>
void BPlusTree<T>::copy_helper(BPlusTreeNode<T>* position, BPlusTreeNode<T>* copy_position) {
    
    // copy all keys from the node
    for (int i = 0; i < copy_position->keys.size(); i++)
        position->keys.push_back(copy_position->keys[i]);
    
    // copy all children of the node or put NULL if there is no child
    for (int i = 0; i < copy_position->children.size(); i++) {
        if (copy_position->children[i]) {
            BPlusTreeNode<T>* new_position = new BPlusTreeNode<T>;
            new_position->parent = position;
            copy_helper(new_position, copy_position->children[i]);
        } else {
            position->children.push_back(NULL);
        }
    }
}




// recursive helper function for delete
template <class T>
void BPlusTree<T>::delete_helper(BPlusTreeNode<T>* position) {
    
    // enters each node and deletes node
    if (position) {
        for (int i = 0; i < position->children.size(); i++)
            delete_helper(position->children[i]);
        delete position;
    }
}




// function to insert values into the tree
template <class T>
void BPlusTree<T>::insert(const T& value) {
    
    // checks if this is the first key in the tree
    if (root) {
        
        // finds where to inser the value
        BPlusTreeNode<T>* insert_position = find(value);
        
        // inserts the value into the node
        insert_position->keys.push_back(value);
        sort((insert_position->keys).begin(), (insert_position->keys).end());
        
        // checks if the leaf must be split into two
        if (insert_position->keys.size() + 1 >= b) {
            
            // seperates the node into two
            seperate(value, insert_position);
        }
    } else {
        
        // if it is the first key, makes a new root node and adds children and the value
        root = new BPlusTreeNode<T>;
        for (int i = 0; i < b; i++)
            root->children.push_back(NULL);
        
        root->keys.push_back(value);
    }
}




// helper function to help split the node
template <class T>
void BPlusTree<T>::seperate(const T& value, BPlusTreeNode<T>* insert_position) {

    // creates new temporary nodes for the split and the new top node if needed
    BPlusTreeNode<T>* new_node1 = new BPlusTreeNode<T>;
    BPlusTreeNode<T>* new_node2 = new BPlusTreeNode<T>;
    BPlusTreeNode<T>* new_node_top = new BPlusTreeNode<T>;
    
    // adds children to each and adds the keys to the new small nodes
    for (int i = 0; i < b; i++) {
        new_node1->children.push_back(NULL);
        new_node2->children.push_back(NULL);
        new_node_top->children.push_back(NULL);
        
        if (i < b/2)
            new_node1->keys.push_back(insert_position->keys[i]);
        else
            new_node2->keys.push_back(insert_position->keys[i]);
    }
    
    // shecks if the node being split is the first node to be split
    if(!insert_position->parent && !insert_position->children[0] && !insert_position->children[1] && !insert_position->children[2]) {
        
        // creates a new set of three nodes
        new_node1->parent = insert_position;
        new_node2->parent = insert_position;
        
        new_node_top->keys.push_back(insert_position->keys[b/2]);
        
        new_node_top->children[0] = new_node1;
        new_node_top->children[1] = new_node2;
        
        insert_position->keys = new_node_top->keys;
        insert_position->children = new_node_top->children;
    }
    // checks if the node being split is the top node
    else if(!insert_position->parent) {
        
        // creates a new set of three nodes and maves all the nodes underneath them
        new_node1->parent = insert_position;
        new_node2->parent = insert_position;
        
        new_node2->keys.clear();
        new_node2->keys.push_back(insert_position->keys[b-1]);
        
        BPlusTreeNode<T>* new_node_child = new BPlusTreeNode<T>;
        new_node_child->keys.push_back(new_node1->keys[0]);
        new_node_child->parent = new_node1;
        
        new_node1->children[0] = insert_position->children[0];
        new_node1->children[1] = new_node_child;
        new_node2->children[0] = insert_position->children[1];
        new_node2->children[1] = insert_position->children[2];
        
        new_node_top->keys.push_back(insert_position->keys[b/2]);
        
        new_node_top->children[0] = new_node1;
        new_node_top->children[1] = new_node2;
        
        
        insert_position->keys = new_node_top->keys;
        insert_position->children = new_node_top->children;
    } else {
        
        // cuts the node in two and pushes the middle value to the node above
        insert_position->parent->keys.push_back(insert_position->keys[1]);
        
        new_node1->parent = insert_position->parent;
        new_node2->parent = insert_position->parent;
        
        insert_position->keys = insert_position->parent->keys;
        
        insert_position->parent->children[1] = new_node1;
        insert_position->parent->children[2] = new_node2;
        
        // checks if the node the values have been added to must also be split
        if (insert_position->parent->keys.size() >= b) {
            seperate(insert_position->parent->keys[b/2], insert_position->parent);
        }
    }
}




// function to find values in the tree
template <class T>
BPlusTreeNode<T>* BPlusTree<T>::find(const T& value) const {
    
    // returns NULL if the tree is empty
    if (!root)
        return NULL;

    // loops until the position is found
    BPlusTreeNode<T>* pos = root;
    while (!pos->is_leaf()) {
        
        // loops through the values in each node
        for (int i = 0; i < pos->keys.size(); i++) {
            
            // if the value is found, it will return position
            if (value < pos->keys[i]) {
                return pos->children[i];
            }
        }
        
        // moves down to the next node from the parent to the child
        if (value > pos->keys[pos->keys.size()-1]) {
            pos = pos->children[pos->keys.size()];
        }
    }
    
    return pos;
}




// function to print values in the tree sideways
template <class T>
void BPlusTree<T>::print_sideways(ofstream& outfile) const {
    
    // checks if the tree has values otherwise prints it is empty
    if (root) {
        
        // stores the number of lines or layers in the tree
        vector<vector<BPlusTreeNode<T>* > > all_lines;
        vector<BPlusTreeNode<T>* > rooti;
        rooti.push_back(root);
        all_lines.push_back(rooti);
        
        // keeps track of the line number and exits when the line number reaches the end of the tree
        int line = 0;
        while (line < all_lines.size()) {
            
            // temporary vector for the values in the next layer
            vector<BPlusTreeNode<T>* > next_line;
            
            // temporary vector for the values to be printed
            vector<BPlusTreeNode<T>* > pos = all_lines[line];
            for (int i = 0; i < pos.size(); i++) {
                
                BPlusTreeNode<T>* pos2 = pos[i];
                
                // iterates through and adds the values found in the next layer
                for (int j = 0; j < pos2->children.size(); j++) {
                    if (pos2->children[j])
                        next_line.push_back(pos2->children[j]);
                }
                
                // printing function
                for (int j = 0; j < pos2->keys.size(); j++) {
                    outfile << pos2->keys[j] << flush;
                    if (j < pos2->keys.size() - 1)
                        outfile << ',' << flush;
                }
                outfile << '\t' << flush;
                
                
            }
            
            // adds value to the vector if there are any values in the next layer
            if (next_line.size() > 0)
                all_lines.push_back(next_line);
            
            outfile << endl;
            
            line++;
            
        }
        
    } else {
        outfile << "Tree is empty." << endl;
    }
}




// function to print values in the tree breadth first
template <class T>
void BPlusTree<T>::print_BFS(ofstream& outfile) const {
    
    // checks if the tree has values otherwise prints it is empty
    if (root) {
        
        // stores the number of lines or layers in the tree
        vector<vector<BPlusTreeNode<T>* > > all_lines;
        vector<BPlusTreeNode<T>* > rooti;
        rooti.push_back(root);
        all_lines.push_back(rooti);
        
        // keeps track of the line number and exits when the line number reaches the end of the tree
        int line = 0;
        while (line < all_lines.size()) {
            
            // temporary vector for the values in the next layer
            vector<BPlusTreeNode<T>* > next_line;
            
            // temporary vector for the values to be printed
            vector<BPlusTreeNode<T>* > pos = all_lines[line];
            for (int i = 0; i < pos.size(); i++) {
                
                BPlusTreeNode<T>* pos2 = pos[i];
                
                // iterates through and adds the values found in the next layer
                for (int j = 0; j < pos2->children.size(); j++) {
                    if (pos2->children[j])
                        next_line.push_back(pos2->children[j]);
                }
                
                // printing function
                for (int j = 0; j < pos2->keys.size(); j++) {
                    outfile << pos2->keys[j] << flush;
                    if (j < pos2->keys.size() - 1)
                        outfile << ',' << flush;
                }
                outfile << '\t' << flush;
                
                
            }
            
            // adds value to the vector if there are any values in the next layer
            if (next_line.size() > 0)
                all_lines.push_back(next_line);
            
            outfile << endl;
            
            line++;
            
        }
        
    } else {
        outfile << "Tree is empty." << endl;
    }
}




#endif
