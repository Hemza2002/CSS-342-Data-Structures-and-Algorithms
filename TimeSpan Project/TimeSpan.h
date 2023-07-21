//
//  TimeSpan.h
//  TimeSpan Assignment
// created by Hemza Al-Shamari 
//
#ifndef TIMESPAN_H
#define TIMESPAN_H
#include <stdio.h>
using namespace std;
//declaring class name 
class TimeSpan
{   //friend function that has access to the private members of the TimeSpan class
    friend ostream& operator<<(ostream &outStream, const TimeSpan &time);
    
public:
    //declaring member functions/constructors and their parameters
    TimeSpan();
    //constructor that takes in a single argument 
    TimeSpan(double s);
     //constructor that takes in two arguments
    TimeSpan(double m, double s);
     //constructor that takes in three arguments
    TimeSpan(double h, double m, double s);
    //getters 
    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    //copy constructor
    TimeSpan(const TimeSpan &t);
    //assigning one TimeSpan object to another using the assignment operator = 
    TimeSpan& operator=(const TimeSpan &t);
    //an overloaded equality operator
    bool operator==(const TimeSpan &t) const;
    //an overloaded inequality operator 
    bool operator!=(const TimeSpan &t) const;
    //an overloaded greater than operator
    bool operator>(const TimeSpan &t) const;
    //an overloaded lessthan operator
    bool operator<(const TimeSpan &t) const;
    //an overloaded greater than or equal operator
    bool operator>=(const TimeSpan &t) const;
    //an overloaded less than or equal operator
    bool operator<=(const TimeSpan &t) const;
    //addition operator
    TimeSpan operator+(const TimeSpan &t) const;
    //subtraction operator
    TimeSpan operator-(const TimeSpan &t) const;
    //compound assignment operator that adds the duration of one TimeSpan object to another
    TimeSpan& operator+=(const TimeSpan &t);
    //compound assignment operator that subtracts the duration of one TimeSpan object from another
    TimeSpan& operator-=(const TimeSpan &t);
    //a multiplication operator that returns a new TimeSpan object representing the product of two TimeSpan objects
    TimeSpan operator*(const TimeSpan &t) const;
    //multiplication operator that returns a new TimeSpan object representing the product of a TimeSpan object and an integer
    TimeSpan operator*(int num) const;
    
//declaring private data members 
private:
    double hour;
    double minutes;
    double seconds;
    TimeSpan& Simplify();
};

#endif