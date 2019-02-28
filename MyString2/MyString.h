#pragma once
#include <iostream>
#include <cstring>
using namespace std;


// MyString class declaration goes here
class MyString
{
private:
     char* ptr;//a pointer to a char
     const char* c_str(); //returns internal c-string pointer as a const pointer
public:
    MyString(); //defalt constructor
    MyString(const char* copyThis); //constructor makes copy of the pointer to a char
    MyString(const MyString & other); //constructor copies MyString to new MyString
    ~MyString(); //destructor (deletes dynamically allocated memory)
    MyString operator= (const MyString &right); //overloaded assignment operator
    MyString operator+ (const MyString &right); //overloaded + operator
    friend ostream &operator << (ostream & strm, const MyString & obj); //friendly overloaded >> operator
    bool operator== (const MyString &right); //overloaded == operator
};