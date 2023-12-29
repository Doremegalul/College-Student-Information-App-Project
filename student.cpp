/*
This program is the setting of all functions of setting up student struct, add courses, view all courses, and remove courses.
*/
#include "student.h"
#include "array.h"

/*
f is a string and the first name
l is a string and the last name
g is a character and the gender
id is a int and the id of the student.

This function is a construct of the student to hold infomation.
*/
Student::Student(string f, string l, char g, int id)
{
  fN = f;
  lN = l;
  gen = g;
  numberClasses = 0;
  stuID = id;
}

/*
This function is a default constructor of student to hold infomation.

*/
Student::Student()
{
  fN = "Unknown";
  lN = "Unknown";
  gen = 'x';
  numberClasses = 0;
  stuID = -1;
}
/*
getFirstName is the return of the first name.

This function is to return first name.
*/
string Student::getFirstName() const
{
  return fN;
}

/*
getLastName is the return of the last name.

This function is to return last name.
*/
string Student::getLastName() const
{
  return lN;
}

/*
getGender is the return of the gender.

This function is to return gender.
*/
char Student::getGender() const
{
  return gen;
}

/*
getNumClasses is the return of the number of classes.

This function is to return number of the classes.
*/
int Student::getNumClasses() const
{
  return numberClasses;
}

/*
getStuID is the return of the student ID.

This function is to return the student ID.
*/
int Student::getStuID() const
{
  return stuID;
}
/*
getClassOf is the return of the index from the info.

This function is to return of the index of info.
*/
int Student::getClassOf(int i) const
{
  if (i > -1 && i <  numberClasses) //If i is less than number of the classes and is greater than -1. Return the class info.
    {
      return num[i];
    }
  else //Else, invalid number.
    {
      cout << "Invalid number";
    }
}

/*
getBalance is the return of the student balance

This function is to return the student balance
*/
Price Student::getBalance() const
{
  return balance;
}

/*
int d is the dollar amount
int c is the cent amount

This function is a void that calculate the increase amount of balance.
*/
void Student::addFee(int d, int c)
{
  Price p(d, c);
  balance = balance + p;
}

/*
int d is the dollar amount
int c is the cent amount

This function is a void that calculate the decrease of balance.
*/
void Student::reduceFee(int d, int c)
{
  Price p(d, c);
  balance = balance - p;
}
/*
crn is the course number

This function is to add the class number to the array.
*/
int Student::addCourse(int crn)
{
  //If the number of classes is less than 6.
  if(numberClasses < MAX)
    {
      int holder = 0;
      holder = find(num, MAX, crn);
      if (holder == -1) //If the holder return -1 then add the class.
	{
     	  num[numberClasses++] = crn;
	  //cout << crn << " has been added to the class array succesfully." <<endl;
	  return 1;       
	}
      else //Else the holder return 0 then don't add the class.
        {
	  //cout << crn << " has not been added because it already exists. " << endl;
	  return 0;
     	}
    }
  else //Else the number of classes is 6 or more.
    {
      //cout << crn << " has not been added because array was full." << endl;
      return -1;
    }
}

/*
viewAllCourses is a function to view all the courses

This function is to print out all the currently courses.
*/
void Student::viewAllCourses() const
{
  //Print out all the current class courses of the student.
  print(num, numberClasses);
  cout << endl;
}

/*
dropCourse is a function to remove a course in the array.
crn is the course number

This function is remove the course in the array.
*/
bool Student::dropCourse(int crn)
{
  bool Holder; //A bool holder
  Holder = remove(num, MAX, crn);
  if (Holder == true) //If the Holder return true
    {
      //cout << "Successful removed." << endl;
      numberClasses --; //To reduce the array size
      return true;
    }
  else //If the Holder return false
    {
      //cout << "Fail to removed." << endl;
      return false;
    }
}
