/*
Minh Tran
CS 211
02-11-2022

This program is a student class to hold private construct and public prototype.
*/

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "price.h"
using namespace std;

const int MAX = 6; //The max size of array.

//Data members.
class Student
{
 private:
  string fN;
  string lN;
  char gen;
  int numberClasses;
  int num[MAX];
  int crn;
  int stuID;
  Price balance;
public:
  Student(string f, string l, char g, int id);
  Student();
  string getFirstName() const;
  string getLastName() const;
  char getGender() const;
  int getNumClasses() const;
  int getStuID() const;
  int getClassOf (int i) const;
  Price getBalance() const;
  void addFee(int d, int c);
  void reduceFee(int d, int c);
  int addCourse(int crn);
  void viewAllCourses() const;
  bool dropCourse(int crn);
};

#endif
