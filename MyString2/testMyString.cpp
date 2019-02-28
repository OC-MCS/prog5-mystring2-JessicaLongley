// main goes in this file
#include <iostream>
#include <cstring>
#include "MyString.h"

using namespace std;
void boringFunction(MyString s);
MyString returningFunction(char a[]);

int main()
{
    //defalt constructor
    MyString S();

    //constructor with (char*) parameter
    MyString S1("abc");
    cout << "After calling (char*) constructor, S: " << S1 << endl << endl;

    //constructor with (MyString parameter)
    MyString S2(S1);
    cout << "After calling (MyString) constructor, S1: " << S1 << " and S2: " << S2 << endl << endl;

    //overloaded operator and copy constructor working in beautifl harmony
    MyString S3("banana");
    MyString S4("apple");
    cout << "assigning S3: " << S3 << " to S4: " << S4 << endl;
    S3 = S4; 
    cout << "after assignment:" << endl;
    cout << "S3: " << S3 << endl;
    cout << "S4: " << S4 << endl << endl;

    //assignment with literal array of characters
    S3 = "bob";
    cout << "Assignment to literal array of characters S3: " << S3 << endl << endl;

    //pass a mystring by value to a function
    boringFunction(S3);

    //return a mystring from a function
    char c[] = "back in main";
    MyString returned = returningFunction(c);
    cout << "A MyString returned from a function: " << returned << endl << endl;

    S3 = S1 + S2;
    cout << S3;
    ////overloaded + operator
    //cout << "Adding with + operator << endl <<  S1: " << S1 << "+ S2: " << S2 << endl;
    //cout << "= " << S1 + S2 << endl;

    //cout << "assigning " << "S3: " << S3 << " to " << "S2: " << S2 << " to " << "S1: " << S1 << endl;
    //S1 = S2 = S3
    //cout << "after assignment: " << endl;
    //cout << "S1: " << S1 << endl;
    //cout << "S2: " << S2 << endl;
    //cout << "S3: " << S3 << endl;


    //cout << "assigning S1: " << S1 << " to " << "S1: " << S1 << endl;
    //S1 = S1;
    //cout << "afterassignment: " << endl;
    //cout << "S1: " << S1 << endl;




    return 0;
}

//there is a MyString that is passed by value to this function
void boringFunction (MyString s)
{
    cout << "copy of MyString passed into function: " << s << endl;
    cout << "No shallow copies here!" << endl << endl;
}

//this function returns a MyString, callig the copy constructor
MyString returningFunction(char a[])
{
    MyString temp(a);

    return temp;
}