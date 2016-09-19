#ifndef A4_PERSON_H
#define A4_PERSON_H
#include <string>
using namespace std;

class Person{//This super class holds the common attributes of Husband,children, and wife.
  friend class Family;//Make Family a friend to this class so that it has access to these methods and attributes.
 protected://We make these attributes protected since 3 class will be utilizing them.
  long SSN;
  string firstName;
  string lastName;
 public:
  Person(long,string,string);//Constructor for Person class to set the attributes.
  void print() const;//A print function that can print the attributes of this class.
};

#endif
