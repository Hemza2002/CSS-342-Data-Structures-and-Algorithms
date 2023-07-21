//
//  TimeSpan.cpp
//  TimeSpan Assignment
// created by Hemza Al-Shamari 
//

#include <iostream>
#include <sstream>
#include <cassert>
#include <iomanip>
#include "TimeSpan.h"
using namespace std;
// testing constructor
void test1() {
    TimeSpan ts( 1 , 20 , 30 );
    stringstream ss;
    cout << "testing <<" << endl;
    ss << ts;
    assert (ss.str() == "1:20:30" );
    cout << "testing overflow and negative inputs" << endl;
    TimeSpan ts2( 4 , - 20 , - 90 );
    ss.str( "" );
    ss << ts2;
    assert (ss.str() == "3:38:30" );
    TimeSpan ts3( 1.5 , 30.5 , - 90 );
    ss.str( "" );
    ss << ts3;
    assert (ss.str() == "1:59:00" );
    TimeSpan ts4( 0 , 0.07 , 0 );
    ss.str( "" );
    ss << ts4;
    assert (ss.str() == "0:00:04" );
}
// testing equality, addition, subtraction, multiplication
void test2() {
    TimeSpan ts( 1 , 20 , 30 );
    TimeSpan ts2( 1 , 20 , 30 );
    TimeSpan ts3( 0 , 0 , 0 );
    TimeSpan ts4(0, 0, 40);
    cout << "testing ==" << endl;
    assert (ts == ts2);
    cout << "testing !=" << endl;
    assert (!(ts != ts2));
    assert (ts != ts3);
    cout << "testing + and **" << endl;
    assert ((ts + ts + ts) == (ts2 * 3 ));
    assert ((ts * 5 ) == (ts2 * 4 ) + ts2);
    assert ((ts * 5 ) == (ts2 * 6 ) - ts2);
    assert ((ts + ts - ts) == ((ts2 * 2 ) - ts));
    cout << "testing -" << endl;
    assert ((ts - ts2) == ts3);
    assert ((ts3 * 5 ) == ts3);
    cout << "testing +=" << endl;
    ts += ts4;
    stringstream ss;
    ss.str( "" );
    ss << ts;
    assert (ss.str() == "1:21:10" );
    cout << "testing -=" << endl;
    ts2 -= ts4;
    ss.str( "" );
    ss << ts2;
    assert (ss.str() == "1:19:50" );
}
void test3()
{
    // comparison operators
    TimeSpan ts1(1, 20, 30);
    TimeSpan ts2(2, 0, 0);
    TimeSpan ts3(1, 20, 30);
    cout << "testing comparison operators" << endl;
    assert(ts1 < ts2);
    assert(!(ts2 < ts1));
    assert(ts2 > ts1);
    assert(!(ts1 > ts2));
    assert(ts1 <= ts2);
    assert (ts1 <= ts3);
    assert (ts2 >= ts1);
    assert (ts1 >= ts3);
}
void testNegative()
{
    TimeSpan ts( 1 , 20 , 30 );
    TimeSpan ts2( 1 , 40 , 30 );
    TimeSpan ts3( 1 , 60 , 30 );
    TimeSpan ts4( 1 , 80 , 30 );
    cout << (ts - ts2) << endl;
    cout << (ts - ts3) << endl;
    cout << (ts - ts4) << endl;
}
void testAll()
{
    test1();
    test2();
    test3();
}
int main() {
    cout << "Begin" << std ::endl;
    testAll();
    cout << "Done." << std ::endl;
    cout<< "The following are testing negative: " << std ::endl;
    testNegative();
    return 0 ;
}
