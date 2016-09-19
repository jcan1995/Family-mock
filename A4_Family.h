/*
4/8/15
Joshua Cantero
cante008@cougars.csusm.edu

The purpose of this assignment was to demonstrate a linklist by making a family tree. A husband is made and considered the "top" of every family. The wife follows the husband, the child follows the wife and the siblings follow the first child made. This assignment was written over the span of 2 weeks.*/



#ifndef A4_FAMILY_H
#define A4_FAMILY_H

#include "A4_Husband.h"//Include this file to have access to Husbands methods and attributes.
#include <string>
using namespace std;

class Family
{
 private: 
  Husband* top;//Make a pointer pointing to husband. This pointer will stay at the "top" of the linklist.
 public:
  Family();//Constructor
  bool AddHusband(long ssn, string F, string L);//This function accepts 3 parameters, the SSN#, first ,and last names of the husband. It will add a new husband.
  bool RemoveHusband(long SSN);//This function accepts the same 3 parameters ass AddHusband does. Although this function removes a husband and may remove the husband's family.
  bool AddWife(long SSN, string Fname, string Lname, long husbandSSN);//This function accepts 4 parameters,SSN#,first and last name, and the husband's SSN. A wife is added to a specific husband depending on the husbandSSN passed.
  bool RemoveWife(long husbandSSN);//This function removes a wife depending on the SSN of the husband.
  bool AddAChild(long SSN, string Fname, string Lname, long fatherSSN);//This function accepts 4 parameters. SSN#,first,last names, and the father's SSN. This function creates a new child under the husband of the SSN# passed in the parameters.
  bool RemoveAChild(long FatherSSN, long childSSN);//This function removes a child under the husband of the SSN# passed and the child SSN# passed in the parameters.
  bool PrintAFamily(long fatherSSN);//This function prints a certain family depending on the SSN passed.
  void PrintAllFamilies();//This function prints all families. The pointer could start at top so no pointer is needed in the parameters.
  void ReadTransactionFile();//This function reads a list of commands and executes them.
  Husband* searchHusband(long id);//This function searches for a certain husband and returns that pointer's position.
};

#endif
