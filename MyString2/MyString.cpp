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
    //cout << "copy constructor is used" << endl;
    int length = strlen(other.ptr)+1; //copy length
    ptr = new char[length];
    strcpy_s(ptr, length, other.ptr); //will this work???    
}

//destructor will delete all allocated memory after the program is finished running
MyString::~MyString()
{
    //cout << "destructor is used" << endl;
    delete[] ptr;
}

//Overloaded = operator
MyString MyString::operator= (const MyString &right)
{
    if (this != &right)
    {
        int length = strlen(right.ptr) + 1;
        delete[] ptr;// delete memory currently being pointed to
        ptr = new char[length];
        strcpy_s(ptr, length, right.ptr);
    }
    return *this; //"this" is a keyword that will return a mystring in this context
}

MyString MyString::operator+ (const MyString &right)
{
    MyString temp;
    int length = strlen(ptr) + strlen(right.ptr) + 1;
    temp.ptr = new char[length];
    strcpy_s(temp.ptr, strlen(ptr) + 1, ptr); //GOOD QUESTION - WHAT ARE THE SIZES SUPPOSED TO MEAN IN THE MIDDLE OF THESE FUNCTIONS?
    strcat_s(temp.ptr, length, right.ptr); //THIS TOOK A LOT OF TRIAL AND ERROR
    return temp;
}

//********************************************************
// Overloaded << operator. Gives cout the ability to     *
// directly display FeetInches objects.                  *
//********************************************************

ostream &operator<< (ostream &strm, const MyString &obj)
{
    strm << obj.c_str();
    
    return strm;
}

bool MyString::operator== (const MyString &right)
{
    return (0 == strcmp(ptr, right.ptr));
}

const char* MyString::c_str() const
{
    return ptr; 
}
