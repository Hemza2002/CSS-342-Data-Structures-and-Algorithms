//
//  assignment4.cpp
//  Lists Assignment
//
// Hemza Al-Shamari
//


#include <iostream>
#include "SkipList.h"
#include <cassert>
#include <climits>

using namespace std;
void test0(){
    //testing empty list with just the guards
    SkipList s(3);
    cout<<s<<endl;
}
void test1() {
    
    //constructor with skiplist depth 4
    SkipList s(4);
    // Adding 

    s.Add(2);
    s.Add(3);
    s.Add(599);
    s.Add(36);
    s.Add(89);
    s.Add(2);
    s.Add(-10);
    s.Add(-195);
    s.Add(292);
    s.Add(522);
    s.Add(222);
    s.Add(634);
    s.Add(822);
    s.Add(990);
    s.Add(9911);
    s.Add(383);
    s.Add(2929);
    s.Add(939);
    s.Add(983);
    s.Add(223);
    s.Add(3311);
    s.Add(3883);
    s.Add(3838);
    s.Add(2738);
    s.Add(3228);
    s.Add(-1233);

    
    //contains method
    assert(s.Contains(223));
    assert(s.Contains(983));
    assert(s.Contains(2929));
    assert(s.Contains(939));
    assert(s.Contains(3311));
    assert(!s.Contains(5));
    assert(!s.Contains(233344));
    
    //test for deleting, deleting already added element and deleting non existent element
    cout<< "skiplist for 4 level"<<endl;
    cout << s << endl;
    cout << "After deleting 223" << endl;
    assert(s.Remove(223));
    cout << s << endl;
    cout << "Aftering deleting 2929"  << endl;
    assert(s.Remove(2929));
    cout << s << endl;
    
    cout << "After Trying to delete element already deleted 1" << endl;
    assert(!s.Remove(223));
    cout << s << endl;
    cout << "After Trying to delete non existing element 333333" <<endl;
    assert(!s.Remove(33333));
    cout << s << endl;


}


void test2() {
    cout << "test 2 with 6 levels" << endl;
    SkipList s(6);
    s.Add(1);
    s.Add(2);
    s.Add(3);
    s.Add(31);
    s.Add(13);
    s.Add(-3);
    s.Add(34);
    s.Add(-34);
    s.Add(333);
    s.Add(-333);
    s.Add(3333);
    s.Add(423);
    s.Add(83);



    //contain test case
    assert(s.Contains(2));
    assert(s.Contains(1));
    assert(s.Contains(-333));
    assert(s.Contains(-333));
    assert(s.Contains(83));
    assert(!s.Contains(-1999999));
    cout << "passed contain methods" << endl;

    cout << "skiplist status "<<endl;
    cout << s << endl;
    cout << "After sucessfully delete 2 " << endl;
    assert(s.Remove(2));
    cout << s << endl;
    cout << "sucessfully delete  1" << endl;
    assert(s.Remove(1));
    cout << s << endl;
    cout << "sucessfully delete -3333"  << endl;
    assert(s.Remove(-333));
    cout << s << endl;
    
    cout << "After Trying to delete non existing element 25 " << endl;
    assert(!s.Remove(25));
    cout << s << endl;
   
    cout << "After Trying to delete element already deleted  2" << endl;
    assert(!s.Remove(2));
    cout << s << endl;
}
//Constructor generating random element to build the linkedList
void test3() {
    
    cout << "Constructor generating random element to build the linkedList "<<endl;
    //5 depth
    SkipList s(5);
    for (int i = 0; i < 20; ++i) {
        int number = rand() % 100;
        s.Add(number);
        cout << "After adding " << number << endl;
        cout << s << endl;
    }
}
void test4(){
    cout << "Constructor generating random element to build the linkedList and then remove it "<<endl;
    //5 depth
    SkipList s(5);
    for (int i = 0; i < 20; ++i) {
        int number = rand() % 100;
        s.Add(number);
        cout << "After adding " << number << endl;
        cout << s << endl;
        s.Remove(number);
        cout << "After removing " << number << endl;
        cout << s << endl;
    }

}
// edge cases where you try to Add INT_MAX and INT_MIN
void test5(){
    SkipList s(3);
    s.Add(INT_MAX);
    s.Add(INT_MIN);
    cout<<s<<endl;
}

// testing adding duplicates
void test8(){
    SkipList s(2);
    
    s.Add(2);
    s.Add(2);
    cout<<s<<endl;
}

int main() {
    test0();
    test1();
    test2();
    test3();
    test4();
    test5();
    test8();
    

    return 0;
}
