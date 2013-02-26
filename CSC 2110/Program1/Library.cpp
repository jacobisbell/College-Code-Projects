/* --- Library.cpp--------------------------------------------------------------
    An implementation file for class type Library and its functions, as well as 
    the Library-nested class type Node and its functions.
    
    Operations are:
        Library()     : Default, zero-argument constructor that sets to NULL the 
                        "first" pointer of the library.
        insert()      : Function that inserts a new article into the list, but 
                        only if the new article's key is unique to that list.
        erase()       : Function that allows the user to delete an article from 
                        the library.
        [PUB]  find() : Function that gives the data of a found article that 
                        matches a user's search criteria based on the results 
                        of its overloaded conterpart NodePointer find().
        [PRIV] find() : Function that takes a searched-for key and returns the 
                        pointer to the article that matches that key, assuming 
                        it exists.
        dispaly()     : Function that displays the entire list of articles in 
                        an easily- read format (uses the operator<< overload).                        
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
#include <iomanip>
#include <string>
#include "Library.h"

using namespace std;

// Default constructor function that assigns a null value to the pointer 
// variable "first."
Library::Library()
{
    first = NULL;
}

// A function that inserts an "item" of type ElementType into the linked list. 
// This function will correctly insert into an empty or populated list. Also, 
// it will populate and update the list in an ordered fashion; specifically, 
// it will sort it alphabetically by key.
void Library::insert(const ElementType &item)
{
    NodePointer ptr     = first;
    NodePointer prevPtr = NULL;
    NodePointer newPtr  = new Node (item);
        
    // Loops through the entire list until the proper position for the new 
    // article is found
    while (ptr != NULL)
    {
        // Correct position has been found-- break out of the loop
        if (item >= ptr->data.key)
            break;
            
        ptr = ptr->next;
        prevPtr = ptr;
    }
    
    if (prevPtr == NULL)         // Algorithm for an empty list
    {
        newPtr->next = first;
        first = newPtr;
    }
    else                        // Counterpart for a non-empty list
    {
        prevPtr->next = newPtr;
        newPtr->next  = ptr;
    }
}

// This function will search the list for a node that contains a key that 
// matches the argument "key" and upon doing so it will return the pointer 
// to this node. If no match is found, it will return NULL.
Library::Node *Library::find(const KeyType &key)
{
    NodePointer ptr = first;
    
    // Loops through the entire list until a match is found (or not found)
    while (ptr != NULL)
    {   
        // If a match has been found, go ahead and return the pointer to 
        // that value
        if (ptr->data.key == key)
            return ptr;

        ptr = ptr->next;
    }
    
    return NULL;    // No matches here! Return resulting NULL value
}

// This function will first check that find(key) is not NULL; if NULL, it 
// will terminate and return false. However, if it is not NULL, it will 
// give the key, author, and title of the article node pointed to by 
// find(key) and return true.
bool Library::find(const KeyType &key, ElementType &item)
{   
	// Go ahead and return false if the article does not exist
	if (find(key) == NULL)
		return false;
        
	NodePointer ptr = find(key);    // Set the pointer to the article
    
	// Retrieve each data item for this article
	item.key    = ptr->data.key;
	item.author = ptr->data.author; 
	item.title  = ptr->data.title;
	
	return true;
}

// A function that accepts a key of type KeyType and deletes the article that 
// this key belongs to. This is achieved by searhing the list until a match is 
// found. Upon finding a match, the article node is deleted, the memory for 
// this node is deallocated, and the preceeding pointer is pointed to the next 
// node. Upon a match being found and a successful deletion being completed, 
// the function returns true. Otherwise, it will return false.
bool Library::erase(const KeyType &key)
{ 
    NodePointer ptr = first;
    NodePointer prevPtr = NULL;
    
    // Loops through the entire list until a match is found (or not found)
    while (ptr != NULL) 
    {
        if (ptr->data.key == key)       // A match has been found!
        {
            if (prevPtr = NULL)        // If previous pointer is the first, fix
                first = ptr->next;
            else                        // Or, fixes the previous node's pointer 
                                        // if it's anywhere else in the list
                prevPtr->next = ptr->next;
      
            delete ptr;
            return true;
        }
        
        prevPtr = ptr;
        ptr = ptr->next;
    }

    return false;       // No matches! (or failure)
}

// This function outputs the entire list of articles in a neat manner by 
// overloading the << operator [BELOW]
// Each article is show by:
// -Key:
// -Title:
// -Author:
void Library::display(ostream &out)
{
    out << "\n------------------------------------------------------------------------------\n" 
        << "-                               Article Listing                              -\n" 
        << "------------------------------------------------------------------------------\n\n";
    
    bool isFirst = true;
    NodePointer ptr = first;
    
    while (ptr != NULL) 
    {
        if (!isFirst)
            out << "\n. . . . . . . . . . . . . . \n\n";
       
        out << "- Key:    " << ptr->data.key    << endl
            << "- Title:  " << ptr->data.title  << endl
            << "- Author: " << ptr->data.author << endl;
            
        ptr = ptr->next;
        isFirst = false;
    }
    
    if (isFirst)
        out << "-                   Sorry, there are no records to display                   -\n";

    out << "\n------------------------------------------------------------------------------\n\n";
}

// cout << operator overload
ostream & operator<<(ostream &out, Library &item)
{
    item.display(out);
    return out;
}

// An overload of the == (equal to) operator. This function allows two keys to 
// be compared, one from Element Type el (el.key), and the other KeyType key. 
// If they are identical, a true value will be returned. Otherwise, false is 
// returned.
bool operator==(const ElementType &el, const KeyType &key)
{
    if (key.compare(el.key) == 0)
        return true;
    else
        return false;
}

// An overload of the >= (greater-than or equal to) operator. This function allows to keys to be compared, one from Element Type el (el.key), 
// and the other KeyType key. If key is alphabetically greater than or equal to el.key, a true value will be returned; otherwise, the function will return false.
bool operator>=(const ElementType &el, const KeyType &key)
{
    if (key.compare(el.key) > 0)
        return true;
    else
        return false;
}
