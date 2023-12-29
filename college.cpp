#include <iostream>
#include <cstdlib> //for atoi() <-- you might not use this
using namespace std;
#include "/cs/slott/cs211/checkInput.h"
#include "student.h"
#include "array.h"
#include <fstream>

const int SIZE = 100; //size of the array
const int START = 100000;//student id starts at 100000
const int PASSWORD = 123; //password for admission's office 
const int PRIME1 = 31; //used to calculate a student's password
const int PRIME2 = 5;

//Beginning:
int showMenu();
int showAdmMenu();
int showStuMenu();
//Phase 1 Prototype:
void addStu(Student studentArray[], int& index, int& ID);
void showStuInfo(Student& s);  
void allStuInfo(Student studentArray[], int index);
bool operator==(const Student& s, int ID); 
void removeStu(Student studentArray[], int& index, int& ID);
void addStuFromFile(Student studentArray[], int& index, int& ID);
//Phase 2 Prototype: 
void addCourse(Student& s);
void dropCourse(Student& s);
void makePayment(Student& s); 
//Phase 3 Prototype:
bool checkPassword(int passwordes);
int findStu(Student studentArray[]);
 
int main()
{
  int count = 0; //the number of students in the array
  int curID = START; //curID is the student id used for the next student you are creating
  
  Student studentArray[SIZE]; //An array of students with the SIZE slots (100 array size)
  
  /*
  //This is the function test.
  addStu(studentArray, count, curID); 
  showStuInfo(studentArray[0]); 
  allStuInfo(studentArray, count);
  */

  int main_menu, admin_menu, student_menu; //Initliaze three different choices
  do //The main menu 
    {
    main_menu = showMenu();
    switch(main_menu) //Based on the main menu choice
      {
      case 1: //Choice to go to the admin menu
	{
	bool passworder = checkPassword(PASSWORD);
	if (passworder == true) //Check the password is true
	  {
	    do //The admin menu
	      {
		admin_menu = showAdmMenu();
		switch(admin_menu) //Based on the admin menu choice
		  {
		  case 1: //Add a student
		    {
		      addStu(studentArray, count, curID);
		      break;
		    }
		  case 2: //Add students from the file
		    {
		      addStuFromFile(studentArray, count, curID);
		      break;
		    }
		  case 3: //Remove a student
		    {
		      removeStu(studentArray, count, curID);
		      break;
		    }
		  case 4: //Find the student
		    {
		      int preindex = findStu(studentArray);
		      if(preindex != -1) //If found the student 
			{
			  showStuInfo(studentArray[preindex]);
			}
		      else //Else not found the student
			{
			  cout << "The student ID doesn't exist. " << endl;
			}
		      break;
		    }
		  case 5: //Show all the students
		    {
		      allStuInfo(studentArray, count);
		      break;
		    }
		  case 6: //Exit the admin menu
		    {
		      break;
		    }
		  }
	      } while (admin_menu != 6);
	  }
      	break;
	}
      case 2: //Choice to go to the student menu
	{
	  int index = findStu(studentArray);
	  if(index != -1) //If found the right student.
	    {   
	      int studentpassword = checkPassword(studentArray[index].getStuID() % (PRIME1 * PRIME2));
	      if (studentpassword == true) //If the student password is right
		{
		  cout << "Welcome " << studentArray[index].getFirstName() << endl;
		  do //The student menu
		    {   
		      student_menu = showStuMenu();
		      switch(student_menu) //Based on the student choice
			{
			case 1: //Add a course
			  addCourse(studentArray[index]);
			  break;
			case 2: //Drop a course
			  dropCourse(studentArray[index]);
			  break;
			case 3: //Make a payment
			  makePayment(studentArray[index]);
			  break;
			case 4: //Show the student info
			  showStuInfo(studentArray[index]);
			  break;
			case 5: //Exit the student menu
			  break;
			} 
		    } while (student_menu != 5);
		}
	      else //Else the student password is wrong
		{
		  //cout << "The password is wrong. " << endl;
		}
	    }
	  else //Else the student was not found
	    {
	      cout << "The student ID doesn't exist. " << endl;
	    }
	  break;
	}	
      case 3: //Exit the main menu
	{
	  break;
	}
      }
  } while (main_menu != 3);

  return 0;
}

// ************************  PHASE 1  ****************************

/*
This function is to ask the user on their first name, last name, and gender. After that, put all the user inputs into an array with the ID while having index increase for the next user input and the ID increase for the unique ID.

studentArray[] is a student array.
index is the count and the array set.
ID is the number of START and for unique student ID. 
*/
void addStu(Student studentArray[], int& index, int& ID)
{
  string fN, lN; //Declare first name(fN) and last name(lN) as string
  char gen; //Declare gender(gen) as char
  cout << "Enter the first name: ";
  cin >> fN;

  cout << "Enter the last name: ";
  cin >> lN;

  cout << "Enter the gender: ";
  cin >> gen;

  Student s(fN, lN, gen, ID); //A student object filled with the user's inputs and ID
  studentArray[index] = s; //Put all the student object into the array.

  index ++; //Increase the index by one for counting the amount of students and set different index for the array.
  ID ++; //Increase the ID by one for the student ID 
}

/*
This funcrion is show full infomation of student.

s is the student object.
*/
void showStuInfo(Student& s)//pass ONE student object - NOT the array  
{                                                                                             //*********************************************************************
//DO NOT send the entire array to this function. BIG deduction if you do.
//SEND only ONE student object as a parameter. If you don't know how, check
//lab1-struct.cpp.
//********************************************************************** 
  cout << "--------------------" << endl;                        
                                                                                             
  cout << "First Name: " << s.getFirstName() << endl;                                                                                                
  cout << "Last Name: " << s.getLastName()  << endl;                                                                                                  
  cout << "Gender: " << s.getGender() << endl;                                                                                                      
  cout << "Student ID: " << s.getStuID() << endl;                                                                                                      
  cout << "Number Classes: " << s.getNumClasses() << endl;                                                                                                                            
  cout << "Courses: ";                                                                                                                        
  for(int i = 0; i < s.getNumClasses(); i++)  //Don't use showAllCourses() but show each course at a time. Which memeber function shows one course?      
    cout << s.getClassOf(i) << ", ";                                                             
  cout << "\nAmount owed $" << s.getBalance() << endl;  //You have an operator overloading function to show a price object at once                   
 
  cout << endl;                                                                                                                               
}

/*
This function is to display all the student infomation based on the amount.

studentArray[] is a student array.
Index is the count and the array set.
*/
void allStuInfo(Student studentArray[], int index)
{
//Case 5 of Admission and case 4 of student
//******************************************
//YOU MUST call showStuInfo() to show each student.
//*******************************************
  for(int i = 0; i < index; i++) //Until the condition is not met, it will display 
    {
      showStuInfo(studentArray[i]);
    }
}



/*
This funcrion is to return true or false based on if the student has an ID or not.

s is the student object in the array.
ID is the student ID.
*/
bool operator==(const Student& s, int ID) 
{
  if(s.getStuID() == ID) //If the user input of student ID is right, return true.
    {
      return true;
    }
  else //Else it is not, return false.
    {
      return false;
    }
}


/*
This function is to remove specific student based on user input ID.

studentArray[] is a student array.
index is the count and the array set.
ID is the number of START and for unique student ID.
*/
void removeStu(Student studentArray[], int& index, int& ID)
{
//Case 3 of Admission

//2 different messages
  int temp; //A temp holder for remove the specific ID
  int search_ID; //A user input on specifc ID
  cout << "Enter the student ID to be remove: ";
  cin >> search_ID;
  for(int i = 0; i < index ; i++) //Until the condition is not met, did the if condition.
    {
      if(studentArray[i].getStuID() == search_ID) //If found the user input of the search ID, then the temp will be that.
	{
	  temp = i;
	}
    }
  
  string fN = studentArray[temp].getFirstName(); //Save the first name in the array for later.
  string lN = studentArray[temp].getLastName(); //Save the last name in the array for later.

  if(remove(studentArray, index, search_ID)) //If the remove successfully, then state out it work.
    {
      cout << fN << " " << lN << " has been removed. " << endl;
      index --;
    }
  else //Else the remove failed, the state out it failed.
    {
      cout << "Student with the ID " << search_ID << " doesn't exist. " << endl;
    }
}

/*
This function is to find the file and add the infomation to the array in student.

studentArray[] is a student array.
index is the count and the array set.
ID is the number of START and for unique student ID.
*/
void addStuFromFile(Student studentArray[], int& index, int& ID)
{
//Case 2 of admission
  
 string filename;
 cout << "Enter a file name: ";
 cin >> filename; //Ask the user what the file to open.

 ifstream fin; //Find the file name and open it to insert the infomation to the array.
 fin.open(filename.c_str());

 if(!fin){ //If the file can't open, it does not exit. 
   cout << filename << "doesn't not exist. " << endl;
  }
 else{ //Else the file can open, insert the first name, last name, and gender.
  string fN, lN;
  char gen;

  fin >> fN;
  fin >> lN;
  fin >> gen;
 
  while(fin) //While the fin is still open, put all the infomation and include increase index and ID.
  {
    Student s(fN, lN, gen, ID);
    fin >> fN;
    fin >> lN;
    fin >> gen;
    studentArray[index] = s;
    index++;
    ID++;
  }
  fin.close(); //Close the file.
 }
}


//*******************  PHASE 2 ****************************

/*
This function is to add the course to the student.

s is the student object
*/
void addCourse(Student& s)//pass only one stuent object - not the array 
{
//case 1 of student
//FYI, I am passing one student to this function not the array.
  int crn;
  cout << "Enter a crn: ";
  cin >> crn; //User input to get course number

  int holder = s.addCourse(crn); //Initalize holder as int and use the addCourse function to add the course number into the student info.
  
//3 different messages to show
  if (holder == 1) //If the holder return 1
    {
      cout << crn << " has been added successfully" << endl;
      s.addFee(50, 14); //Use addFee to give 50 dollar and 14 cent into the student info.
    }
  else if (holder == 0) //If the holder return 0
    {
      cout << crn << " was not added because you have " << crn << " already." <<  endl;
    }
  else //Else the holder return something else.
    {
      cout << crn << " was not added because your schedule is full." <<  endl;
    }

}

/*
This function is to drop the course to the student

s is the student object
*/
void dropCourse(Student& s)//pass only one stuent object, not the array
{
//case 2 of admission
//FYI, I am passing one student to this function not the array.
  int crn;
  cout << "Enter a crn: ";
  cin >> crn; //User input to get course number

  bool Holder = s.dropCourse(crn); //Initalize holder as bool and use the dropCourse function to add the course number into the student info.

//2 different messages
  if (Holder == false) //If the holder return false
    {
      cout << crn << " wasn't dropped from " << s.getFirstName() << " because " << crn << " doesn't exist" << endl;
    }
  else //Else the holder return true
    {
      cout << crn << " has been dropped successfully." << endl;
      s.reduceFee(50, 14); //Use reduceFee to give 50 dollar and 14 cent into the student info.
    }
}

/*
This function to make the payment from the student and check the payment is right

s is the student object
*/
void makePayment(Student& s) //pass one student object - not the array
{
  string Pay;
  cout << "You owe $" << s.getBalance() << endl;
  cout << "Enter your payment: ";
  cin >> Pay; //User input to the amount to be pay.
  int d, c; //Initialize d and c as int for insert dollar and cent
  string cent, dollar; //Initialize cent and dollar as string for insert to int later
  if (Pay.find(".") == -1) //If it only dollar
    {
      d = atoi(Pay.c_str()); //Using atoi to convert string to int
      c = 0;
    }
  else //Else it is dollar and cent
    {
      cent = Pay.substr(Pay.find(".") + 1, Pay.length() - (Pay.find(".") + 1)); //Find the demical then minus it with length to get the demical point. Credit to Daniel.
      c = atoi(cent.c_str()); //Using atoi to convert string to int
      
	if (cent.length() != 2) //If the cent is NOT in 2 places
	  {
	    cout << "The amount is in a Wrong format. " << endl;
	    return;
	  }
	else //Else it is in 2 places
	  {
	    if (Pay.find(".") != 0) //If the dollar is not 0
	      {
		dollar = Pay.substr(0, Pay.find(".")); //Find the demical at the 0
		d = atoi(dollar.c_str()); //Using atoi to convert string to int
	      }
	    else //If the dollar is 0
	      {
		d = 0;
	      }
	  }
    }

//case 3 of student
//FYI, I am passing one student to this function not the array.
  Price p(d, c); //Initiliaze to price to be compare
  if (p > s.getBalance()) //If p is greater than the balance to be owe
    {
      cout << "You owe " << s.getBalance() << " and you are trying to pay too much. " << endl;
    }
  else //Else it is not
    {
      s.reduceFee(d, c); //Reduce the fee
    }
}


//******************** PHASE 3 ****************************

/*
This function is to check the password and return true or false

passwordes is the int that set from the main to be the right password
*/
bool checkPassword(int passwordes)
{
  //To ask the password
  int non_password;
  cout << "Enter the password: ";
  cin >> non_password;
 
  if (non_password == PASSWORD) //If the user input is 123, it will go forward.
    {
      //To make space.
      //cout << endl << endl;
      return true;
    }
  else if (non_password == passwordes) //If the user input is based on the parameter, then return true.
    {
      return true;
    }
  else //Else, the user will go back.
    {
      //To tell the password is wrong.
      cout << "The Password is wrong." << endl << endl;
      return false;
    }
}

/*
This function is to find the student based on the ID.

studentArray is the student inside the array
*/
int findStu(Student studentArray[])
{
  int key; //To save the user input in int 
  cout << "Enter the student id: ";
  cin >> key;
  int search_ID = find(studentArray, SIZE, key); //Used the find function to find the student in the array
  if (search_ID != -1) //If found the student
      {
	for(int i = 0; i < SIZE - 1; i++) //Go through the array in the size array
	  {
	    if (studentArray[i] == key) //If found the student in the array
	    {
	      return i; //Return the right index that have student and it ID
	    }
	  }
      } 
  else //If not found the student
      {
	return -1; //Return -1 to show as not found
      }
}

/*
 viewStuInfo()
{
//Case 4 of admission
//Ask for the student id
//If the student doesn't exist, show an error message.
//If it exists, call showStuInfo to show the student
}


 verifyStu()
{
//You may decide not to use this function. If so, that is OK.

//When the user is a student, select 2 in the top menu. He/she enters hi/her student id.
//Make sure the stuent id exists in the array. If not, I am showing an error message.
//FYI, I am returning the index where the student was found or -1 if not found.
}

*/

/*
This function is to show the menu for the user input
 
*/
int showMenu()
{
  int choice;
  cout << "========================================================" << endl;
  cout << "1: Admission's Office" << endl;
  cout << "2: Student" << endl;
  cout << "3: End program" << endl;
  cout << "========================================================" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 3, "\tInvalid choice. Enter only 1, 2 or 3: ");

  return choice;
}

/*
This function is to show the student menu for the user input

*/
int showStuMenu()
{
  int choice;

  cout << endl;
  cout << "***************************" << endl;
  cout << "1: Add a course" << endl;
  cout << "2: drop a course" << endl;
  cout << "3: Make a payment" << endl;
  cout << "4: View my information" << endl;
  cout << "5: Quit" << endl;
  cout << "***************************" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 5, "\tInvalid choice. Enter only 1 through 5: ");

  return choice;
}

/*
This function is to show the admin menu for the user input

*/
int showAdmMenu()
{
  int choice;

  cout << endl;
  cout << "***************************" << endl;
  cout << "1: Add a new student" << endl;
  cout << "2: Add new students from a file" << endl;
  cout << "3: drop a student" << endl;
  cout << "4: View one student info" << endl;
  cout << "5: View all students' info" << endl;
  cout << "6: Quit" << endl;
  cout << "***************************" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 6, "\tInvalid choice. Enter only 1 through 6: ");

  return choice;
}



