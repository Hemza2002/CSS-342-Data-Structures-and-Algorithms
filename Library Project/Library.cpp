//
//  Library.cpp
//  Library Assignment
//
//  Hemza Al-Shamari
//  HW1 - Library Classes
//
using namespace std;
#include "Library.h"
Library::Library() {
    
}
Library::Library(const string &name) {
    nameOfLibrary = name;
}
Library::~Library() {
}

// Add a new book,
// return true for success, false if book already in library
bool Library::AddBook(const string &name) {
    if(IsInLibrary(name)) {
        return false;
    }
    else if(numberOfBooks == MAX_NUMBER_BOOKS) {
        return false;
    }
      
    else{
        books[numberOfBooks] = name;
        numberOfBooks++;
        return true;
    }
}
//removes book depending if the book is in the library
bool Library::RemoveBook(const string &name){
    if(!IsInLibrary(name)) {
        return false;
    }else{
        books[findBook(name)] = books[numberOfBooks - 1];
        numberOfBooks--;
        return true;
    }
}
//lists all books
void Library::ListAllBooks() const {
    for(int i = 0; i < numberOfBooks; i++) {
        cout << books[i] << "\n";
    }
    
}
//checks wether or not the book is in the library
bool Library::IsInLibrary(const string &name){
    if(findBook(name) != -1) {
        return true;
    }else{
        return false;
    }
}
//finds the book
int Library::findBook (const string &name) const{
    for(int i = 0; i < numberOfBooks; i++) {
        if(books[i] == name) {
            return i;
        }
    }
    return -1;
}

 //Print the library name and a list of books
 ostream &operator<<(ostream &out, const Library &lib) {
    for (int i = 0; i < lib.numberOfBooks; i++)
    {
        out << lib.books[i] << ", ";
    }
    return out;
}
