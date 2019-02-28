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
    cout << "After calling constructor(char*), S1: " << S1 << endl << endl;

    //constructor with (MyString parameter)
    MyString S2(S1);
    cout << "After calling constructor(MyString) , S1: " << S1 << " and S2: " << S2 << endl << endl;

    //overloaded operator and copy constructor working in beautifl harmony
    MyString S3("banana");
    MyString S4("apple");
    cout << "assigning S3: " << S3 << " to S4: " << S4 << endl;
    S3 = S4; 
    cout << "after assignment:" << endl;
    cout << "S3: " << S3 << endl;
    cout << "S4: " << S4 << endl << endl;

    //pass a mystring by value to a function
    boringFunction(S3);

    //return a mystring from a function
    char c[] = "back in main";
    MyString returned = returningFunction(c);
    cout << "A MyString returned from a function: " << returned << endl << endl;

    //assignment with literal array of characters
    cout << "Redefine S2 to hold 123 ";
    S2 = "123";
    cout << "After statement, S2 = " << S2 << endl << endl;

    cout << "Change values in S1 and S2" << endl;
    S1 = "hello ";
    S2 = "world!";
    //overloaded + operator
    cout << "Adding with + operator << endl <<  S1: " << S1 << " + S2: " << S2 << " = S3 " << endl;
    S3 = S1 + S2;
    cout << "S3 = " << S3 << endl<< endl;

    cout << "(Resetting values of S1, S2, S3 " << endl;
    S1 = "dog";
    S2 = "cat";
    S3 = "fish";

    cout << "assigning " << "S3: " << S3 << " to " << "S2: " << S2 << " to " << "S1: " << S1 << endl;
    cout << "S1 = S2 = S3" << endl;
    S1 = S2 = S3;
    cout << "after assignment: " << endl;
    cout << "S1: " << S1 << endl;
    cout << "S2: " << S2 << endl;
    cout << "S3: " << S3 << endl << endl;


    cout << "assigning S1: " << S1 << " to " << "S1: " << S1 << endl;
    cout << "S1 = S1" << endl;
    S1 = S1;
    cout << "after assignment: " << endl;
    cout << "S1: " << S1 << endl << endl;

    //check operloaded == operator
    cout << "content of S1: " << S1 << endl;
    cout << "contents of S2: " << S2 << endl;
    cout << "Are S1 and S2 equal? " << endl;
    if (S1 == S2)
    {
        cout << "yes!" << endl;
    }
    else
        cout << "no!" << endl << endl;

    cout << "Are S1 and 'fish' equal? " << endl;
    if (S1 == "fish")
    {
        cout << "yes!" << endl;
    }
    else
        cout << "no!" << endl;



    return 0;
}

//there is a MyString that is passed by value to this function
void boringFunction (MyString s)
{
    cout << "copy of MyString passed into function: " << s << endl;
    cout << "(That means success)" << endl << endl;
}

//this function returns a MyString, callig the copy constructor
MyString returningFunction(char a[])
{
    MyString temp(a);

    return temp;
}