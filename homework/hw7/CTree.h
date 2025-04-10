#ifndef _CTREE_H
#define _CTREE_H

#include <cstdlib>
#include <string>

// ordered tree of characters
class CTree {

public:

    // constructor
    CTree(char ch);

    // copy constructor
    CTree(const CTree &tree);

    // destructor
    ~CTree();

    // assignment operator
    CTree& operator=(const CTree &rhs);

    // operator to do the same thing as addChild
    CTree& operator+=(CTree &rt);

    // return true if two CTrees match node by node
    bool operator==(const CTree &rhs);

    // siblings and children must be unique
    // return true if added, false otherwise
    bool addChild(char ch);

    // add tree root for better building, root should have null prev and sibs
    // returns false on any type of failure, including invalid root
    bool addChild(CTree *t);

    // all characters in preorder separated by newlines, including at the end
    std::string toString();

private:

    // the value stored in the tree node
    char data;

    // children - pointer to first child of list, maintain order & uniqueness
    CTree * kids;

    // siblings - pointer to rest of children list, maintain order & uniqueness
    // should always be null if the object is the root of a tree
    CTree * sibs;

    // pointer to parent if this is a first child, or left sibling otherwise
    // should always be null if the object is the root of a tree
    CTree * prev;

    // these should only be called from addChild, and have the same restrictions
    // the root of a tree should never have any siblings
    // returns false on any type of failure, including invalid root
    bool addSibling(char ch);
    bool addSibling(CTree *t);

    // returns true if trees a and b are identical, false otherwise
    // (helper method to implement == operator)
    friend bool treeCompare(const CTree *a, const CTree *b);

    // returns pointer to a new tree that is a duplicate of *t
    // caller is responsible for updating result's root prev field (copy's
    // inner prevs will be set)
    // (helper method to implement copy constructor and assignment operator)
    friend CTree* createDuplicateTree(const CTree *t);

    friend class CTreeTest;

};

std::ostream& operator<<(std::ostream& os, CTree& rt);

#endif
