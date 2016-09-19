#include "A4_Husband.h"
#include <iostream>
#include <string>
using namespace std;

Husband::Husband(long id,string Fname,string Lname):Person(id,Fname,Lname)
{
  myWife = NULL;
  nextFamily = NULL;
}

void Husband::print() const
{
  cout<<"SSN: "<<SSN<<endl;
  cout<<"First Name: "<<firstName<<endl;
  cout<<"Last Name: "<<lastName<<endl;
}
