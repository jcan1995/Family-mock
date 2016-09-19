#ifndef A4_HUSBAND_H
#define A4_HUSBAND_H
#include <iostream>
#include "A4_Wife.h"
#include "A4_Person.h"//Include this file since the husband class will be inheriting attributes from it.
#include <string>
using namespace std;

class Husband: public Person{//This is how we will inherit the first 3 attributes for husband from the class Person.
  friend class Family;//Makes Family a friend of this class so Family has access to its members and methods.
 private:
  Husband* nextFamily;
  Wife* myWife;
 public:
  Husband(long,string,string);//This constructor will pass attributes to class Person.
  void print()const;
};
#endif
