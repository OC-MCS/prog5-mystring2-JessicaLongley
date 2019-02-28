#pragma once
#include <iostream>
#include <cstring>
using namespace std;


// MyString class declaration goes here
class MyString
{
private:
     char* ptr;//a pointer to a char
public:
    MyString(); //defalt constructor
    MyString(const char* copyThis); //constructor makes copy of the pointer to a char
    MyString(const MyString & other);
    ~MyString(); //destructor (deletes dynamically allocated memory)
    MyString operator= (const MyString &right); //overloaded assignment operator
    MyString operator+ (const MyString &right); //overloaded + operator
    friend ostream &operator << (ostream & strm, const MyString & obj); //friend overloaded >> operator
};