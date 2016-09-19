#ifndef A4_WIFE_H
#define A4_WIFE_H

#include "A4_Child.h"
#include "A4_Person.h"//Include this file so we are able to inherit attributes from it.
#include <string>
using namespace std;

class Wife:public Person
{
  friend class Family;//Make Family a friend of this class to have access to its methods and members.
 private:
  Child* myChildren;//Make a pointer from Wife called myChildren.
 public:
  Wife(long,string,string);//This constructor will pass its parameters to class person to set the attributes.
  void print() const;//This function prints out the required information.
};
#endif
