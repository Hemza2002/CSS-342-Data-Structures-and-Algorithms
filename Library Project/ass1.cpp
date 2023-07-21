#include <iostream>
#include <cassert>
#include "Library.h"


void Test1 () {
    Library libs("UWB");
    libs.AddBook("Don Quixote");
    libs.AddBook("In Search of Lost Time");
    libs.AddBook("Ulysses");
    libs.AddBook("The Odyssey");
    libs.ListAllBooks();
    //should generate already in library message and return true
    bool result = libs.IsInLibrary("The Odyssey");
    assert(result);

    // cannot add book twice, result should be false
    result = libs.AddBook("the Odyssey");
    assert(!result);

    // test remove, result should be true
    result = libs.RemoveBook("The Odyssey");
    assert(result);

    // not in library, result should be false
    result = libs.IsInLibrary("The Odyssey");
    assert(!result);
    
    // cannot remove twice, result should be false
    result = libs.RemoveBook("The Odyssey");
    assert(!result);

}

void TestAll() {
    Test1();
    std::cout << "Successfully completed all tests." << std:: endl;
}
int main() { 
TestAll();
return 0;
}