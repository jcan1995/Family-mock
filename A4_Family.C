#include <iostream>
#include <fstream>
#include <string>
#include "A4_Family.h"//Include this file to have references for functions and members.
using namespace std;
Family::Family()
{
  top = NULL;//Set top equal to NULL.
}
bool Family::AddHusband(long ssn, string F, string L)//This function will add a husband to the family. All husbands should be added no matter what their info is.
{
  Husband* p = new Husband(ssn,F,L);//Make a husband node passing these parameters and have 'p' point to it.
  if(top == NULL)//If top equals NULL, make top equal to the new node.
    {
      top = p;
      p -> nextFamily = NULL;//Set the "nextFamily" pointer equal to NULL after a husband is made.
      return true;//Return true.
    }
  else{
    Husband* q = top;//If a husband was already made make a pointer that points to the top node.
    while(q -> nextFamily != NULL)//This loop is used to move to the bottom of the husband link list.
      {
	q = q -> nextFamily;//q equals q -> nextFamily if it doesn't equal NULL.
      }
    q -> nextFamily = p;//Make the last pointer point to the new node.
    p -> nextFamily = NULL;//Make the pointer of the new node equal to NULL.
  }
  return true;//Return true.
}
///////////////////////////////////////////////////////////////////////////////////////////////
Husband* Family::searchHusband(long id)//This function returns a pointer. If the husband SSN is found, return the address of the pointer.
{
  Husband* p = top; //Make p equal the top husband.
  while(p != NULL)//Loop used to move through the link list of husbands.
    {
      if(p -> SSN == id)//If the Id's match return that pointer.
	return p;//This is where the pointer is returned.
      else 
	p = p -> nextFamily;//else move on to the next node and try again.
    }
  return NULL;//If no matching SSN was found just return NULL.
}
///////////////////////////////////////////////////////////////////////////////////////////////
bool Family::AddWife(long SSN, string Fname, string Lname,long husbandSSN)//This function adds a wife to a certain husband depending on the SSN recieved here.
{
  Husband* H = searchHusband(husbandSSN);//Here 'H' equals whatever pointer that is going to be passed back from the "searchHusband" function. 
  if(H == NULL)//If H equals NULL it means that the SSN wasn't found.
    return false;//So return false.
  Wife* W = new Wife(SSN,Fname,Lname);//If it is found then make a wife node.
  H -> myWife = W;//Make that husband's pointer "myWife" equal to the new node.
}
///////////////////////////////////////////////////////////////////////////////////////////////
bool Family::AddAChild(long SSN, string Fname, string Lname, long fatherSSN)//This function will add a new child to a family depending on the SSN passed in the parameters.
{
  Husband* H = searchHusband(fatherSSN);//Here 'H' equals whatever pointer that is going to be passed back from the "searchHusband" function.
  if(H == NULL)//If H equals NULL it means that the SSN wasn't found.
    return false;//Return false.
  Wife* w = H -> myWife;//Make a wife pointer pointing to whatever the "myWife" is pointing at.
  Child* t = w -> myChildren;//Make a Child pointer pointing to whatever the Wife's "myChildren" points to.
  Child* C = new Child(SSN,Fname,Lname);//Make a new Child node passing these parameters.
  w -> myChildren = C;//Tie the knots and ensure there are no memory leaks.
  C -> mySibling = t;
}
///////////////////////////////////////////////////////////////////////////////////////////////
bool Family::RemoveAChild(long FatherSSN, long childSSN)//This function eletes a child node depending on the SSNs passed in the parameters.
{
  Husband* H = searchHusband(FatherSSN);//Here 'H' equals whatever pointer that is going t\o be passed back from the "searchHusband" function.
  if(H == NULL)//If H equals NULL it means that the SSN wasn't found.
    return false;//Return false.
  Wife* w = H -> myWife;//Make a wife pointer pointing to Husband's "myWife".
  Child* C = w -> myChildren;//Make a child pointer pointing to Wife's "myChildren" pointer.
  while(C != NULL){//Use this condition to scroll through the list of children.
    if(C -> SSN == childSSN)//If the SSNs match make sure to attach the Wife's my children pointer to the node in front of the deleted node to prevent a memory leak.
      {
	w ->myChildren = C -> mySibling;//Here is where my have "myWife" point to the child following the deleted child.
	delete C;//Delete the node .
	return true;//Return true.
      }
    else
      C = C ->mySibling;//If SSNs don't match, move on and try again.
  }
  return false;//Return false.
}

bool Family::RemoveWife(long husbandSSN)//This function removes a wife and children if there are any.
{
  Husband* H = searchHusband(husbandSSN);
  Wife* w = H -> myWife;
  if(w -> myChildren != NULL)
    {
      Child* C = w -> myChildren;
      RemoveAChild(husbandSSN, C -> SSN);
    }
  delete w;
  H -> myWife = NULL;
}
	
bool Family::RemoveHusband(long SSN)//This function removes husband along with his wife and children if there are any.
{
  Husband* H = searchHusband(SSN);
  if(H -> myWife != NULL)
    {
      RemoveWife(SSN);
      delete H;
      return true;;
    }
  else
    delete H;
  return true;
}



///////////////////////////////////////////////////////////////////////////////////////////////
bool Family::PrintAFamily(long fatherSSN)//This function prints a certain family depending on the SSN passed in the parameters.
{
  Husband* z = searchHusband(fatherSSN);
  if(z == NULL)
    return false;
  cout<<"Husband Info: "<<endl;
  cout<<"SSN: "<<z -> SSN<<endl;
  cout<<"First Name: "<<z -> firstName<<endl;
  cout<<"Last Name: "<<z -> lastName<<endl;
  cout<<endl;  
  Wife* W = z -> myWife;
  if(W == NULL)
    return true;
  cout<<"Wife Info: "<<endl;
  cout<<"SSN: "<<W -> SSN<<endl;
  cout<<"First Name: "<<W -> firstName<<endl;
  cout<<"Last Name: "<<W -> lastName<<endl;
  cout<<endl;
  Child* C = W -> myChildren;
  while(C != NULL)
    {
      cout<<"Child Info: "<<endl;
      cout<<"SSN: "<<C -> SSN<<endl;
      cout<<"First Name: "<<C -> firstName<<endl;
      cout<<"Last Name: "<<C -> lastName<<endl;
      cout<<endl;
      C = C -> mySibling;    
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////
void Family::PrintAllFamilies()//This function prints all of the existing families. 
{
  Husband* p = top;
  while(p != NULL)
    {
      PrintAFamily(p -> SSN);
      p = p -> nextFamily;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////
void Family::ReadTransactionFile()//This function reads in a list of commands from the transaction file and executes certain functions depending on the command read.
{
  ifstream fin;//Variable consisting of the file.
  string cmd;//Variable that takes in the command from the transaction file.
  long SSN;//VAriable that reads in the SSN number.
  string Fname;//Variable reads in the first name.
  string Lname;//Variable reads in the last name.

  long HusFathId;//VAriable that reads in the SSN of the dad.
  fin.open("A4TRANSACTIONTEST.txt");
  if(fin.fail())
    {
      cout<<"File doesn't exist"<<endl;
      exit(1);
    }
  while(!fin.eof())
    {
      fin>>cmd;
      if(cmd == "AddHusband"){
	fin>>SSN>>Fname>>Lname;
      bool check = AddHusband(SSN,Fname,Lname);
      if(check == true)
	cout<<"Husband SSN#: "<<SSN<<" successfully added!"<<endl;
      else
	cout<<"Husband SSN#: "<<SSN<<" could not be added!"<<endl;
      }
      else if(cmd == "PrintAFamily")
	{
	  fin>>SSN;
	  bool check = PrintAFamily(SSN);
	  if(check == false)
	    cout<<"SSN#: "<<SSN<<" does not exist! Cannot be printed!"<<endl<<endl;	
	}
      else if(cmd =="AddWife"){
	fin>>SSN>>Fname>>Lname>>HusFathId;
	bool check = AddWife(SSN,Fname,Lname,HusFathId);
	if(check == true){
	  cout<<"Wife SSN#: "<<SSN<<" was successfully added!"<<endl;
	}
	else
	  cout<<"Wife SSN#: "<<SSN<<" could not be added!"<<endl;
      }
      else if(cmd =="PrintAllFamilies"){
	PrintAllFamilies();
      }
      else if(cmd =="AddAchild"){
	fin>>SSN>>Fname>>Lname>>HusFathId;
	bool check = AddAChild(SSN,Fname,Lname,HusFathId);
	if(check == false){
	  cout<<"Child SSN#: "<<SSN<<" could not be added!"<<endl;
	}	 
	else
	  cout<<"Child SSN: "<<SSN<<" was successfully added!"<<endl;
      }
      else if(cmd =="RemoveAchild"){
	fin>>HusFathId>>SSN;
	bool check = RemoveAChild(HusFathId,SSN);
	if(check == true)
	  cout<<"Child SSN#: "<<SSN<<" was successfully removed!"<<endl;
	else
	  cout<<"Child SSN#: "<<SSN<<" could not be removed!"<<endl;
      }
    }
}
