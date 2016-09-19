#include <iostream>
#include "A4_Person.h"
#include <string>
using namespace std;
Person::Person(long ID,string First,string Last)//This constructor accepts parameters from husband,children,and wife classes and sets them.
{
  SSN = ID;
  firstName = First;
  lastName = Last;
}

void Person::print()const//This function will print out attributes if necessary.
{
  cout<<"SSN: "<<SSN<<endl;
  cout<<"First Name: "<<firstName<<endl;
  cout<<"Last Name: "<<lastName<<endl;
}
