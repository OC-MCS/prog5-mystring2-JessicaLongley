//=============================
//Jessica Longley
//1 MAR 2019
//Programming Assignment #5
//Description: MyString class
//=============================

//Future improvement to this code:
//Create more functions to deal with empty MyStrings.#include <iostream>
#include <cstring>
#include "MyString.h"

using namespace std;
void coolFunction(MyString s);
MyString returningFunction();

int main()
{
    //Ways to create instances of MyStrings
    cout << "The defalt constructor initializes the MyString(S) pointer to nullptr." << endl << endl;
    MyString S();

    cout << "You can use a literal string (abc) to initialize MyString (S1)." << endl;
    MyString S1("abc");
    cout << "After initalizing:" << endl;
    cout << "S1: " << S1 << endl << endl;

    cout << "Initialize a MyString (S2) with a MyString (S1) as the parameter." << endl;
    MyString S2(S1);
    cout << "After initalizing:" << endl;
    cout << "S1: " << S1 << "    S2 : " << S2 << endl << endl;

    cout << "Initialize a MyString (S5) by passing a variable reference to an array of chars." << endl;
    char name[] = "andy";
    MyString S5(name);
    cout << "After initalizing:" << endl;
    cout << "S5: " << S5 << endl << endl;


    //overloaded operator and copy constructor working in beautiful harmony
    MyString S3("banana");
    MyString S4("apple");
    cout << "Assign one MyString (S3: " << S3 << ") to another MyString (S4: " << S4 << ")." << endl;
    S4 = S3; 
    cout << "After assignment:" << endl;
    cout << "S3: " << S3 << endl;
    cout << "S4: " << S4 << endl << endl;

    
    cout << "Pass a MyString by value to a function such as (coolFunction) that makes a deep copy and displays value passed." << endl;
    coolFunction(S3);
    cout << "Function has been executed." << endl << endl;

    cout << "Return a MyString from a function such as (ReturningFunction)."<< endl;
    MyString S6 = returningFunction();
    cout << "MyString (S6) returned from a function: " << S6 << endl;
    cout << "MyString (S6) was initialized inside this function." << endl << endl;

    //assignment with literal array of characters
    cout << "Redefine MyString (S1) to hold literal c-string (hello) ";
    cout << "Redefine MyString (S2) to hold literal c-string (world) ";
    S1 = "hello ";
    S2 = "world!";
    cout << "After change: " << endl;
    cout << "S1: " << S1 << endl;
    cout << "S2: " << S2 << endl;

    //overloaded + operator
    cout << "Add MyString to MyString with + operator. "<< endl;
    cout << "S1: (" << S1 << ") + S2: (" << S2 << ") = S3 " << endl;
    S3 = S1 + S2;
    cout << "After using + operator: " << endl;
    cout << "S3 = " << S3 << endl<< endl;

    cout << "(Resetting values of S1, S2, S3)." << endl;
    S1 = "dog";
    S2 = "cat";
    S3 = "fish";

    cout << "assigning " << "S3: (" << S3 << ") to " << "S2: (" << S2 << ") to " << "S1: (" << S1 << ")" << endl;
    cout << "S1 = S2 = S3" << endl;
    S1 = S2 = S3;
    cout << "After assignment: " << endl;
    cout << "S1: " << S1 << endl;
    cout << "S2: " << S2 << endl;
    cout << "S3: " << S3 << endl << endl;


    cout << "assigning S1: (" << S1 << ") to " << "S1: (" << S1 << ")" << endl;
    cout << "S1 = S1" << endl;
    S1 = S1;
    cout << "After assignment: " << endl;
    cout << "S1: " << S1 << endl << endl;

    //operloaded == operator
    cout << "Are S1 (fish) and S2 (fish) equal? " << endl;
    if (S1 == S2)
    {
        cout << "yes!" << endl << endl;
    }
    else
        cout << "no!" << endl << endl;

    cout << "Are S1 (fish) and S6 (Hello) equal? " << endl;
    if (S1 == S6)
    {
        cout << "yes!" << endl << endl;
    }
    else
        cout << "no!" << endl << endl;

    cout << "Are S1 and 'fish' equal? " << endl;
    if (S1 == "fish")
    {
        cout << "yes!" << endl << endl;
    }
    else
        cout << "no!" << endl << endl;

    return 0;
}

//there is a MyString that is passed by value to this function
void coolFunction (MyString s)
{
    cout << "Deep copy of MyString passed into function: " << s << endl << endl;
}

//this function returns a MyString, callig the copy constructor
MyString returningFunction()
{
    MyString temp("Hello");

    return temp;
}