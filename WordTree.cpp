//
//  WordTree.c
//  Homework 4
//
//  Created by Ava Gonick on 8/18/23.
//

#include "WordTree.h"

//wordNode constructor sets val to 1, data to whatever data is given and left and right points to nullptr
WordNode::WordNode(WordType data){
    m_data = data;
    m_left = nullptr;
    m_right = nullptr;
    m_val = 1;
}


//member function to be used in the copy constructor
WordNode* WordTree::createWordTree(WordNode* val){
    //return nullptr if val is the nullptr
    if(val == nullptr)
        return nullptr;
    
    //get left hand wordNode
    WordNode* left = createWordTree(val->m_left);
    
    
    //get right hand wordNode
    WordNode* right = createWordTree(val ->m_right);
    
    //proccess this node
   WordNode* newVal = new WordNode(val->m_data);
    //set the newVal numbers to the same as the old one
    newVal->m_val = val->m_val;
    
    //add left and right nodes
    newVal->m_left = left;
    newVal->m_right = right;
    
    //return 
    return newVal;
}

//copy constructor
//everything has to be a new node
//in order traversal 
WordTree::WordTree(const WordTree& rhs){
    //create new trea setting the root to the new root
    root = createWordTree(rhs.root);
}

//delete everything
void WordTree::deleteTree(WordNode* val){
    if(val == nullptr)
        return;
    
    //go through left so it gets deleted 
    deleteTree(val->m_left);
    
    //go through right so it gets deleted
    deleteTree(val->m_right);
    
    //delete val at end so no recursive issues
    delete val;
}

//assignment operator 
const WordTree& WordTree::operator=(const WordTree& rhs){
    
    //delete everything in the root
    deleteTree(root);
    
    //then create everything a new
    root = createWordTree(rhs.root);
    
    //always end assignment operator retuning this
    return *this;
}

WordTree::~WordTree(){
    //go through and delete everythign
    deleteTree(root);
}


void WordTree::add(WordType v){
    
    //if root is nullptr then just make it a new node and return
    if(root == nullptr){
        root = new WordNode(v);
        return;
    }
    
    //else look for the right spot
    WordNode* it = root;
    for(;;){
        //if getData and its the same just return
        if(it->m_data == v){
           it-> m_val ++;
            return;
        }
        
        //if value less than current value move to the left
        if(v < it->m_data){
            if(it ->m_left == nullptr){
                it->m_left = new WordNode(v);
                return;
            }
            else
                it = it-> m_left;
        }
        //if value is greater than current value add to the right
        
        //if value less than current value move to the left
        if(v > it->m_data){
            if(it ->m_right == nullptr){
                it->m_right =new WordNode(v);
                return;
            }
            else
                it = it->m_right;
        }
        
    }
}


//gets the number of Distinct worlds
int WordTree::helperDistinctWords(WordNode* val) const{
    if(val == nullptr)
        return 0;
    int numLeft = helperDistinctWords(val->m_left);
    
    int numRight = helperDistinctWords(val->m_right);
    
    //need to add one to include self
    return numLeft+numRight + 1;
}


//iterate through everything adding 1 to count each time 
int WordTree::distinctWords() const{
    return helperDistinctWords(root);
}


//helper functions that finds the total number of words
int WordTree::helperAllWords(WordNode* val) const{
    if(val == nullptr)
        return 0;
    int numLeft = helperAllWords(val->m_left);
    
    int numRight = helperAllWords(val->m_right);
    
    //need to add number in val
    return numLeft+numRight + val->m_val;
}

int WordTree::totalWords() const{
    return helperAllWords(root);
}


//helper function that prints out all of the words
void WordTree::helperPrintAll(std::ostream& out,WordNode* val) const{
    if(val == nullptr)
        return;
    
    helperPrintAll(out, val->m_left);
    
    out << val -> m_data << " " << val->m_val << std::endl;
    
    helperPrintAll(out, val ->m_right);
}

//in line for printing
std::ostream& operator<<(std::ostream& out, const WordTree& rhs){
    rhs.helperPrintAll(out, rhs.root);
    
    return out;
}
