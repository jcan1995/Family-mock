#ifndef A4_CHILD_H
#define A4_CHILD_H
#include "A4_Person.h"//Include this file to accept parameters from this class.
#include <string>
using namespace std;

class Child:public Person{
  friend class Family;//Make Family a friend to this class so it has access to this class's members and methods.
 private:
  Child* mySibling;
 public:
  Child(long,string,string);
  void print() const;
};

#endif
