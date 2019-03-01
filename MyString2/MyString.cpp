#include "MyString.h"
#include<iostream>
#include<cstring>

using namespace std;

//************************************************************
//Defalt constructor.                                        *
//Assigns MyString's ptr to  nullptr if no chars are passed. *
//************************************************************
MyString::MyString()
{
    ptr = nullptr;
}

//******************************************************
//Construtor that takes char* as a parameter           *   
//to inialize the MyString                             *
//******************************************************
MyString::MyString(const char* copyThis)
{
        int length = strlen(copyThis);//length is how big to make the copy
        ptr = new char[length + 1];//Dynamically allocating enough space for the copy
        strcpy_s(ptr, length + 1, copyThis);//Copying
}

//*******************************************************
//Copy constructor. Makes DEEP copies.                  *
//*******************************************************
MyString::MyString(const MyString & other)
{
    cout << "copy constructor is used" << endl;
    int length = strlen(other.ptr)+1;//How big to make copy
    ptr = new char[length];//Make space for copy
    strcpy_s(ptr, length, other.ptr);//Make copy
}

//**************************************************************
//Destructor function. Will delete all dynamically allocated   *
//memory after the program is finished running.                *
//**************************************************************
MyString::~MyString()
{
    cout << "destructor is used" << endl;
    delete[] ptr;//destruct dynamically allocated memory
}

//********************************************************
// Overloaded = operator. Gives user the ability to      *
// assign one MyString to another.                       *
//********************************************************
MyString MyString::operator= (const MyString &right)
{
    if (this != &right)
    {
        int length = strlen(right.ptr) + 1;
        delete[] ptr;// delete memory currently being pointed to
        ptr = new char[length];//make enough space for the new data
        strcpy_s(ptr, length, right.ptr);//copy data over
    }
    return *this; //"this" is a keyword that will return a MyString
}

//********************************************************
// Overloaded + operator. Gives user the ability to      *
// concatenate MyStrings.                                *
//********************************************************
MyString MyString::operator+ (const MyString &right)
{
    MyString temp;
    int length = strlen(ptr) + strlen(right.ptr) + 1;//Length is both and a null byte
    temp.ptr = new char[length];//Make space in new MyString
    strcpy_s(temp.ptr, strlen(ptr) + 1, ptr);//Copy over the left string
    strcat_s(temp.ptr, length, right.ptr);//Concatenate with the right string
    return temp;
}

//********************************************************
// Overloaded << operator. Gives cout the ability to     *
// directly display MyString objects.                    *
//********************************************************
ostream &operator<< (ostream &strm, const MyString &obj)
{
    strm << obj.c_str();//cout the char array
    
    return strm;
}

//********************************************************
// Overloaded == operator. Gives user the ability to     *
// compare MyString objects.                             *
//********************************************************
bool MyString::operator== (const MyString &right)
{
    return (0 == strcmp(ptr, right.ptr));//compare the two MyStrings and return T/F
}

//*******************************************************************
//c_str function. Returns constant ptr to the initialized MyString. *
//This prevents us from making any friends :/                       *
//*******************************************************************
const char* MyString::c_str() const
{
    return ptr; //No friends needed.
}