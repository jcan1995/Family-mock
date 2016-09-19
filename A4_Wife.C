#include "A4_Wife.h"
#include <iostream>
#include <string>
using namespace std;

Wife::Wife(long ID,string First,string Last):Person(ID,First,Last)
{
  myChildren = NULL;
}

void Wife::print() const
{
  cout<<"SSN: "<<SSN<<endl;
  cout<<"First Name: "<<firstName<<endl;
  cout<<"Last Name: "<<lastName<<endl;
}
