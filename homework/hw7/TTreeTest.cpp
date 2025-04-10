#include "Tree.h"
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::string;

class TTreeTest {

public:

    // test constructor of a template Tree for different types
    static void testConstructor() {

        // build a few trees with constructor
        // Tree of char
        Tree<char>* t1 = new Tree<char>('A');
        assert(t1->toString() == "A\n");

        // Tree of int
        Tree<int>* t2 = new Tree<int>(32);
        assert(t2->toString() == "32\n");

        // Tree of float
        Tree<short>* t3 = new Tree<short>(255);
        assert(t3->toString() == "255\n");

        delete t1;
        delete t2;
        delete t3;

    }

    // test addChild and addSibling for templated Tree with type argument int
    static void testAdd() {

        // 1
        Tree<int>* t1 = new Tree<int>(1);
        assert(t1->toString() == "1\n");

        // 1
        // |
        // 7
        assert(t1->addChild(7));
        assert(t1->toString() == "1\n7\n");
        // can't add again
        assert(!t1->addChild(7));
        assert(t1->toString() == "1\n7\n");

        // 1
        // |
        // 4 - 5
        assert(t1->addChild(8));
        assert(t1->toString() == "1\n7\n8\n");
        // can't add again
        assert(!t1->addChild(8));
        assert(t1->toString() == "1\n7\n8\n");

        // 1
        // |
        // 3 - 4 - 5
        assert(t1->addChild(6));
        // 2 comes before 3
        assert(t1->toString() == "1\n6\n7\n8\n");
        // can't add repeats
        assert(!t1->addChild(6));
        assert(!t1->addChild(7));
        assert(!t1->addChild(8));
        assert(t1->toString() == "1\n6\n7\n8\n");

        // can't add 1 as sibling of 1
        assert(!t1->addSibling(1));
        assert(t1->toString() == "1\n6\n7\n8\n");

        // make sure that we can't add siblings to the root
        assert(!t1->addSibling(1));
        assert(t1->toString() == "1\n6\n7\n8\n");

        // Adding a subTree
        // First build another tree
        // 2
        Tree<int>* t2 = new Tree<int>(2);

        assert(t2->toString() == "2\n");

        // 2
        // |
        // 4
        assert(t2->addChild(4));
        assert(t2->toString() == "2\n4\n");

        // 2
        // |
        // 4 - 5
        assert(t2->addChild(5));
        assert(t2->toString() == "2\n4\n5\n");
        // can't repeat
        assert(!t2->addChild(5));
        assert(t2->toString() == "2\n4\n5\n");

        // 2
        // |
        // 6 - 7 - 8
        assert(t2->addChild(3));
        assert(t2->toString() == "2\n3\n4\n5\n");
        // can't repeat
        assert(!t2->addChild(3));
        assert(t2->toString() == "2\n3\n4\n5\n");

        // Add t2 in as a child
        // 1
        // |
        // 2 - 6 - 7 - 8
        // |
        // 3 - 4 - 5

        // t1 is as before
        assert(t1->toString() == "1\n6\n7\n8\n");
        // add t2 to t1
        assert(t1->addChild(t2));
        // t1 should now include all numbers 1 through 8
        assert(t1->toString() == "1\n2\n3\n4\n5\n6\n7\n8\n");
        // t2 should be updated to have siblings
        assert(t2->toString() == "2\n3\n4\n5\n6\n7\n8\n");

        // Since t2 was attached under t1, only t1 needs to be deleted
        delete t1;

    }

    // test += operator for a template Tree
    static void testPlusEqualsOp() {

        // 1
        // |
        // 2 - 3
        Tree<int>* t1 = new Tree<int>(1);
        assert(t1->addChild(2));
        assert(t1->addChild(3));

        // 4
        // |
        // 5 - 6
        Tree<int>* t2 = new Tree<int>(4);
        assert(t2->addChild(5));
        assert(t2->addChild(6));

        // 1
        // |
        // 2 - 3 - 4
        //         |
        //         5 - 6
        *t1 += *t2;
        assert(t1->toString() == "1\n2\n3\n4\n5\n6\n");
        assert(t2->toString() == "4\n5\n6\n");

        // Since t2 was attached under t1, only t1 needs to be deleted
        delete t1;

    }

    // test << operator for a template Tree
    static void testOutputOp() {

        // 1
        // |
        // 2 - 3 - 4 - 5 - 6
        Tree<int>* t1 = new Tree<int>(1);
        assert(t1->addChild(2));
        assert(t1->addChild(3));
        assert(t1->addChild(4));
        assert(t1->addChild(5));
        assert(t1->addChild(6));

        std::ostringstream o;
        o << *t1;
        assert(o.str() == t1->toString());

        delete t1;

    }

    // test adding a single child for template Tree
    static void testAddSimpleChild() {

        // ali
        Tree<string>* t1 = new Tree<string>("ali");
        assert(t1->toString() == "ali\n");

        // ali
        Tree<string>* t2 = new Tree<string>("ali");
        assert(t2->toString() == "ali\n");

        // ali
        // |
        // ali
        assert(t2->addChild(t1));
        assert(t2->toString() == "ali\nali\n");
        assert(t1->toString() == "ali\n");

        delete t2;

    }

    // test == operator
    static void testEqualityOp() {

        Tree<string>* t1 = new Tree<string>("ali");
        assert(t1->addChild("sara"));
        assert(t1->addChild("joanne"));
        assert(t1->addChild("peter"));

        Tree<string>* t2 = new Tree<string>("ali");
        assert(t2->addChild("sara"));
        assert(t2->addChild("joanne"));
        assert(t2->addChild("peter"));

        assert (*t1 == *t2);

        Tree<int>* t3 = new Tree<int>(1);
        assert(t3->addChild(2));
        assert(t3->addChild(3));

        Tree<int>* t4 = new Tree<int>(1);
        assert(t4->addChild(3));
        assert (!(*t3 == *t4));

        delete t1;
        delete t2;
        delete t3;
        delete t4;

    }

    // assumes == operator works
    static void testCopyConstructor() {

        Tree<int>* t1 = new Tree<int>(1);
        assert(t1->addChild(2));
        assert(t1->addChild(3));
        assert(t1->addChild(4));
        assert(t1->addChild(5));
        assert(t1->addChild(6));

        Tree<int>* t2 = new Tree<int>(*t1);

        assert(*t1 == *t2);

        // copy constructor duplicates tree so both need to be deleted
        delete t1;
        delete t2;

    }

    // assumes == operator works
    static void testAssignmentOperator() {

        Tree<int>* t1 = new Tree<int>(1);
        assert(t1->addChild(2));
        assert(t1->addChild(3));
        assert(t1->addChild(4));
        assert(t1->addChild(5));
        assert(t1->addChild(6));

        Tree<int>* t2 = new Tree<int>(-1);

        Tree<int>* t3 = new Tree<int>(-2);
        assert(t3->addChild(-3));

        *t3 = *t2 = *t1;

        assert(*t2 == *t1);
        assert(*t3 == *t1);

        // assignment operator duplicates tree so they all need to be deleted
        delete t1;
        delete t2;
        delete t3;
        
    }

};

int main() {

    cout << "Testing Tree" << endl;
    TTreeTest::testConstructor();
    TTreeTest::testAdd();
    TTreeTest::testAddSimpleChild();
    TTreeTest::testPlusEqualsOp();
    TTreeTest::testOutputOp();
    TTreeTest::testEqualityOp();
    TTreeTest::testCopyConstructor();
    TTreeTest::testAssignmentOperator();
    cout << "Tree tests passed" << endl;

}
