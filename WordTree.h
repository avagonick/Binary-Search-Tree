//
//  WordTree.h
//  Homework 4
//
//  Created by Ava Gonick on 8/18/23.
//

#ifndef WordTree_h
#define WordTree_h

#include <iostream>
#include <string>
typedef std::string WordType;
struct WordNode {
WordType m_data;
WordNode *m_left;
WordNode *m_right;
    int m_val; //holds number of this value
    
    //constructor
    WordNode(WordType data);
// You may add additional data members and a constructor

};
class WordTree {
private:
WordNode *root;
    WordNode* createWordTree(WordNode* val);
    void deleteTree(WordNode* val);
    
    int helperDistinctWords(WordNode* val) const;
    
    int helperAllWords(WordNode* val) const;
    
    void helperPrintAll(std::ostream& out, WordNode* val) const; 

public:
// default constructor, sets root to the nullptr
WordTree() : root(nullptr) { };
    
// copy constructor
WordTree(const WordTree& rhs);
    
// assignment operator
const WordTree& operator=(const WordTree& rhs);
    
//Inserts v into the WordTree
void add(WordType v);
    
// Returns the number of distinct words / nodes
  int distinctWords() const;
    
    // Returns the total number of words inserted, including
    // duplicate values
  int totalWords() const;
    
    // Prints the WordTree
friend std::ostream& operator<<(std::ostream& out, const WordTree& rhs);
    
    // Destroys all the dynamically allocated memory in the
    // tree
   ~WordTree();
    };

#endif /* WordTree_h */
