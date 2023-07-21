//
//  Library.h
//  Library Assignment
//
//  Hemza Al-Shamari
//  HW1 - Library Classes
//

#ifndef Library_h
#define Library_h

#include <iostream>



using namespace std;
class Library {

 //private variables
    private :
    static const int MAX_NUMBER_BOOKS = 100;
    int numberOfBooks;
    int findBook (const string &name) const;
    string name;
    string books[MAX_NUMBER_BOOKS];
    string nameOfLibrary;
    
    
    //public methods 
    public:
    Library();
    Library(const string &name);
    ~Library();
    bool AddBook(const string &name);
    void ListAllBooks() const;
    bool IsInLibrary(const string &name);
    bool RemoveBook(const string &name);
    friend ostream &operator<<(ostream &out, const Library &lib);
   
    
   
};
#endif /* Library_h */