/* --- main.cpp-----------------------------------------------------------------
    This program reads the contents of file that contains a library of articles 
    from the journal "Communications of the ACM" and places each one into a node
    of a linked list in alphabetical order by their key values. Each article 
    contains three pieces of data: its key, author, and title. The reading and 
    storing of this information is done at the program's start; once these 
    actions have been completed successfully, the user is informed by a welcome 
    message. The user is then presented with a menu of options. This menu will 
    continue to display (even after the user enters and exits a menu option) 
    until the user indicates that he/she wishes to exit the program by using 
    option 'E'.
        Option 'F' allows the user to search the list by typing in the access 
    key of an article. If there is a match in the list, it will be displayed to 
    the user.  Otherwise, the program will inform the user that no matches were 
    found.
        Option 'L' displays the whole list of articles to the user in a very 
    neat and orderly manner.
        Option 'A' allows the user to add a new article to the list. Upon 
    choosing this option, the user will be prompted to enter a key for his or 
    her new article.  If this key exists, the program will inform the user of 
    this conflict and prompt the user for a different key. This will continue 
    until the user enters a valid, non-existent key. Once a valid key is entered, 
    the program will prompt the user for the author's name and the article's 
    title. It will then insert the new article into the list, display a message 
    confirming the insertion, and display the data that was just inserted.
        Option 'R' allows the user to remove an article from the list. Upon 
    choosing this option, the user will be prompted to enter a key for the 
    article that is to be removed. If this key does not exists, the program will 
    inform the user of this and return to the main menu. Otherwise, it will 
    delete the indicated article, and display a message confirming this deletion 
    along with the key of the deleted article.    

    Written by:  John Smith                Tennessee Technological University
    Written for: CSC 2110                        January 19th, 2012
------------------------------------------------------------------------------*/
#include "Library.h" //Need to import Library header for "Library" type
#include <cstdlib>   //Need to import for the exit call in line 72
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>

// Menu and menu-option function prototypes
char menu();
void findArticle(Library &article);
void addArticle(Library &article);
void removeArticle(Library &article);


using namespace std;


int main()
{
    Library article;
    ElementType fileData;
    KeyType keyData;
    bool showMenu = true;

    // Open file of name "fileName"; return an error and exit the program upon 
    // failure
    ifstream file;
    char fileName[15] = "cacmpubs10.txt";
    file.open(fileName);

    cout << "\n$ cacmLibrary " << fileName << endl;
    
    if (file.fail())
    {
        cout << "The file \"" << fileName << "\" failed to open.\n\n";
        exit(1);
    }
    else
        cout << "Loading library, please wait..." << endl;

    // Continues reading, storing, and inserting data as long as there are 
    // contents left in the file
    while (!file.eof())
    {    
        // Reads and stores the article's key
        getline(file, keyData);
        fileData.key = keyData.substr(0, keyData.size()-1);
        
        // Reads and stores the article's author
        getline(file, fileData.author);
       
        // Reads and stores the article's title
        getline(file, fileData.title);
        
        // Checks to make sure the file is not reading a blank line (or keyless 
        // article) If valid, inserts the compiled stored data into the linked 
        // list
        if (fileData.key != "")
            article.insert(fileData);
    }
    
    file.clear();
    file.close();

    cout << "Welcome to the CACM Library!\n\n";
    
    // Continues to show the user a menu of program options until he indicates 
    // he would like to exit
    while (showMenu == true)
    {
        char menuChoice = toupper(menu());
     
        switch (menuChoice)
        {
            case 'F':
                findArticle(article);
                break;
            case 'L':
                cout << article;
                break;
            case 'A':
                addArticle(article);
                break;
            case 'R':
                removeArticle(article);
                break;
            case 'E':
                showMenu = false;
                break;
            default:
                cout << "Invalid Menu Choice -- Please Try Again\n\n";
                break;
         }
    }
    
    cout << "Thank you for using the CACM Library!\n$\n";

    return 0;
}

// Displays a text-based menu for the user
// Returns the character of the user's choice for use in the menu's display in 
// the main() function
char menu()
{
    char response;

    cout << "What would you like to do?\n\n"
         << "(F)ind an article\n"
         << "(L)ist all articles\n"
         << "(A)dd a new article\n"
         << "(R)emove an existing article\n"
         << "(E)xit\n\n"
         << "Your choice > ";
    cin  >> response;
    cout << endl;

    return response;
}

// This option allows the user to search the list for a specific article
void findArticle(Library &article)
{
    ElementType data;
    KeyType key;
    
    cout << "Please enter a search key: ";
    cin >> key;
    
    cout << "\n-------------------------------------------------------------------------------\n"; 
    
    if (article.find(key, data))
    {
        cout << "- Key:    " << data.key    << endl
             << "- Title:  " << data.title  << endl
             << "- Author: " << data.author << endl;
    }
    else
        cout << "-            Sorry, but there are no records matching your query              -\n";
        
    cout << "-------------------------------------------------------------------------------\n\n";
}

// Allows the user to add their own article assuming it does not already exist
void addArticle(Library &article)
{
    ElementType data;
    KeyType key;
    string author, title;
    bool validEntry = false;
    
    // Continues to prompt the user for a valid, non-existent article key
    while (!validEntry)
    {
        cout << "Please Enter the key for your new article: ";
        cin >> key;
        
        if (article.find(key, data))
            cout << "\nThis key already exists!\n\n";
        else
            validEntry = false;
    }
    
    cin.ignore();
    
    cout << "Enter the author's name: ";
    getline (cin, author);
    
    cout << "Enter the title of the article: ";
    getline (cin, title);
    
    data.key    = key;
    data.title  = title;
    data.author = author;
    
    article.insert(data);   // Inserts the new article into the linked list
    
    cout << "\n-------------------------------------------------------------------------------\n"
         << "- The Following record has been ADDED:                                        -\n"
         << "-                                                                             -\n"
         << "- Key:    " << setw(68) << left << data.key    << right << "-\n" 
         << "- Title:  " << setw(68) << left << data.title  << right << "-\n"
         << "- Author: " << setw(68) << left << data.author << right << "-\n"
         << "-------------------------------------------------------------------------------\n\n";
}

// Allows the user to delete an article from the list assuming the specified 
// article exists
void removeArticle(Library &article)
{
    ElementType data;
    KeyType key;
    
    cin.ignore();
    cout << "Enter the key for the article that you want to remove: ";
    getline (cin, key);
    
    // If the article exists, it will be erased and the user will be informed
    // Otherwise, the user will be shown that the article did not exist, and 
    // no action will be taken
    if (article.erase(key))
    {
        cout << "\n-------------------------------------------------------------------------------\n"
             << "-                The Following record has been REMOVED:                       -\n"
             << "-                                                                             -\n"
             << "- Key: " << setw(71) << left << key << right << "-\n"
             << "-------------------------------------------------------------------------------\n\n";
    }
    else
    {
        cout << "\n-------------------------------------------------------------------------------\n"
             << "-      Sorry, record not removed because it was not found in the database     -\n"
             << "-------------------------------------------------------------------------------\n\n";
    }
}
