#include "MyString.h"
#include<iostream>
#include<cstring>

using namespace std;

//defalt constructor
MyString::MyString()
{
    ptr = nullptr;
}

//construtor that takes char* as a parameter to inialize the MyString
MyString::MyString(const char* copyThis)
{
    int length = strlen(copyThis); 
    ptr = new char[length + 1];
    strcpy_s(ptr, length + 1, copyThis);
}

//copy constructor
MyString::MyString(const MyString & other)
{
    int length = strlen(other.ptr); //copy length
    ptr = new char[length + 1];
    strcpy_s(ptr, length+ 1, other.ptr); //will this work???    
}

//destructor will delete all allocated memory after the program is finished running
MyString::~MyString()
{
    delete[] ptr;
}

//Overloaded = operator
MyString MyString::operator= (const MyString &right)
{
    if (this != &right)
    {
        delete[] ptr;// delete memory currently being pointed to
        ptr = new char[strlen(right.ptr) + 1];
        strcpy_s(ptr, strlen(right.ptr) + 1, right.ptr);
    }
    return *this; //"this" is a keyword that will return a mystring in this context
}

MyString MyString::operator+ (const MyString &right)
{
    MyString temp;
    int length = strlen(ptr) + strlen(right.ptr) + 1;
    temp.ptr = new char[length];
    strcat_s(temp.ptr, strlen(ptr), ptr);
    strcat_s(temp.ptr, strlen(right.ptr) + 1, right.ptr);
    return temp;
}

//********************************************************
// Overloaded << operator. Gives cout the ability to     *
// directly display FeetInches objects.                  *
//********************************************************

ostream &operator<< (ostream &strm, const MyString &obj)
{
    for (int i = 0; i < strlen(obj.ptr); i++)
    {
        strm << obj.ptr[i]; //what i want to do here is display the char that the pointer is pointing to at that index
    }
    return strm;
}