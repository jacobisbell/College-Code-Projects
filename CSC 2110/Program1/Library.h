/* --- Library.h ---------------------------------------------------------------
    A header file for class type Library that defines the functions and 
    variables that allow a user to add, find, and delete library objects 
    (articles). Class type Node is also declared here, but within the Library 
    class.
    
    Operations are:
        Library()     : Default, zero-argument constructor that defines the size 
                        of the library list.
        insert()      : Function that inserts a new article into the list, but 
                        only if the new article's key is unique to that list.
        erase()       : Function that allows the user to delete an article from 
                        the library.
        [PUB]  find() : Function that gives the data of a found article that 
                        matches a user's search criteria based on the results of 
                        its overloaded conterpart NodePointer find().
        [PRIV] find() : Function that takes a searched-for key and returns the 
                        pointer to the article that matches that key, assuming 
                        it exists.
        dispaly()     : Function that displays the entire list of articles in an 
                        easily-read format (uses the operator<< overload).                        
        Node()        : Default, one-argument constructor that sets the node's 
                        "data" equal to the argument "item." 
                        
        operator << overload
        operator == overload : operator overload that compares two articles' 
                               keys, looks for equivalency, and returns the 
                               correct boolean value for the result of the 
                               comparison.
        operator >= overload : operator overload that compares two articles' 
                               keys and returns the correct boolean value for 
                               the comparison.

    Written by: John Smith                   Tennessee Technological University
    Written for: CSC 2110                         January 19th, 2012
------------------------------------------------------------------------------*/

#include <iostream>
#include <string>

using namespace std;

typedef struct Article_s ElementType;
typedef std::string KeyType;

// Data structure for each article's information
struct Article_s
{
    KeyType key;
    string author;
    string title;
};

class Library
{
    public:
        Library();
        void insert(const ElementType &item);
        bool find(const KeyType &key, ElementType &item);
        bool erase(const KeyType &key);
        void display(ostream &out);
    private:
        class Node
        {
            public:
                ElementType data;
                Node *next;
                Node(const ElementType &item)
                {
                    data = item;
                }    
        };        
        typedef Node *NodePointer;
        NodePointer first;
        NodePointer find(const KeyType &key);        
};

ostream & operator<<(ostream &out, Library &item);
bool operator==(const ElementType &el, const KeyType &key);
bool operator>=(const ElementType &el, const KeyType &key);
