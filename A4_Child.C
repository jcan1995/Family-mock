#include "A4_Child.h"
#include <iostream>
#include <string>
using namespace std;

Child::Child(long ID,string FIRST,string LAST):Person(ID,FIRST,LAST)//This constructor takes in 3 parameters but passes them to person class to be initialized.
{
  mySibling = NULL;//Set mySibling equal toNULL
}

void Child::print() const//This function can print out the information of a student.
{
  cout<<"SSN: "<<SSN<<endl;
  cout<<"First Name: "<<firstName<<endl;
  cout<<"Last Name: "<<lastName<<endl;
}
