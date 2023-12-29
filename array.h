/*****************************************************
Template prepared by Kazumi Slott
CS211
lab on template functions
This header file provides useful operations on an array
of any data type.

Your name: Minh Tran
*****************************************************/
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <iomanip>
using namespace std;

/********************************************
This function fills the array with data entered from the keyboard.

ar is an array of any data type
n is the number of items entered into ar
********************************************/
template <class T>
void fill(T ar[], int n) {
  //Filling in the item into the array.
  for (int i = 0; i < n; i++){
    cout << "Enter an item: ";
    cin >> ar[i];
  }
}

/********************************************
This function prints the array.

ar is an array of any data type
n is the number of items in ar
********************************************/
//         print
template <class T>
void print(const T ar[], int n) {
  //Printing out the item in the array
  for (int i = 0; i < n; i++){
    cout << ar[i] << " ";
  }
}

/*******************************************
This function returns the index of the highest value.

ar is an array of any data type.
n is the number of items in ar
*******************************************/
//       getHighest
template <class T>
int getHighest(const T ar[], int n){
  int highest = 0;
  //Go through the entire and check if the item is higher than the current highest array. Then the highest become that item.
  for (int i = 1; i < n; i++){
    if (ar[i] > ar[highest]){
      highest = i;
    }
  }
  return highest;
}

/*******************************************
This function returns the index of the lowest value.

ar is an array of any data type.
n is the number of items in array
*******************************************/
//       getLowest
template <class T>
int getLowest(const T ar[], int n){
  int lowest = 0;
  //Go through the entire and check if the item is lower than the current highest array. Then the lowest become that item.
  for (int i = 1; i < n; i++){
    if (ar[i] < ar[lowest]){
      lowest = i;
    }
  }
  return lowest;
}

/********************************************
This function returns the average.

ar is an array of any data type.
n is the number of items in ar
********************************************/
//       getAvg
template <class T>
double getAvg(const T ar[], int n){
  double sum = 0;
  //To go through the array and combine them together to get the average at the end.
  for (int i = 0; i < n; i++){
    sum += ar[i];
  }
  return (double)sum/n;
}

/*******************************************
This function stores unique items into an array
and returns the number of the unique items.
  e.g.  If ar contains  9 3 5 3 9 1 9
        uniqAr gets 9 3 5 1
        The function returns 4

ar is the original array of any data type
uniqAr is the array that will have only unique items
n is the number of items in ar and uniqAr
*******************************************/
template <class T>
int unique(const T ar[], T uniqAr[], int n) {
  int counter = 0;
  int j, i;
  //To go through the array.
  for (i = 0; i < n; i++){
    //To go through the array and check if there the same value in the array then break it.
    for (j = 0; j < i; j++){
      if (ar[i] == ar[j]){
        break;
      }
    }
    if (i == j){
      uniqAr[counter] = ar[i];
      counter ++;
    }
  }
  return counter;
}
//uniqAr in the caller will be filled with only unique numbers

/***********************************************
This function sorts the items in ascending order: smallest to largest

array is an array of any data type
N is the number of items in the array
**********************************************/

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//The following function sorts an integer array in ascending order
//using the selection sort algorithm.
//You need to change this code so it works with an array of any data type.
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
template <class T>
void sort(T array[], int N)
{
  int lrgIndx; //the index of the largest value
  T temp; //temporary variable that holds the largest value

  //last is the last index in unsorted portion
  for(int last = N-1; last >= 1; last--){
    {
      lrgIndx = 0; //assume the first item is the largest
      //find the largest in unsorted portion ([0..last])
      for(int i = 1; i <= last; i++) {
	if(array[i] > array[lrgIndx]){ //The current item is larger
	  lrgIndx = i;
	}
      }
      //swap the largest with the last item in the unsorted portion
      temp = array[lrgIndx];
      array[lrgIndx] = array[last];
      array[last] = temp;
    }
  }
}

/***********************************************
This function sorts by swapping the items until the end in descending order: largest to smallest

array is an array of any data type
N is the number of items in the array
**********************************************/
template <class T>
void bubbleSort(T array[], int N){

  bool done; //To set a bool function
  done = false; //To set it false.

  T temp; //temporary variable that holds the smallest value

  while (!done) //While the condition is false
    {
      done = true; //To end the condition
      //Start in the first number and count up all the number in the array.
      for(int i = 0; i < N-1; i++)
	{
	  if(array[i] < array[i + 1]) //The current item is smaller
	    { 
	      //swap the smallest with the last item in the unsorted part
	      temp = array[i];
	      array[i] = array[i + 1];
	      array[i + 1] = temp;
	      done = false; //To continue the while loop.
	    }
	}
      N--; //To go the next array.
    }
}

/*
This function is to find the data type in the array and return 1 if successful or return -1 if fail.

array is an array of any data type
N is the number of the array.
key is the data type looking for. 
 */
template <class T, class T2>
int find (const T array[], int N, const T2& key)
{
  for(int j = 0; j < N; j++) //To go through the array.
    {
      if (array[j] == key) //If the array is equal to the key then return the array number.
	{
	  return j;
	}
    }
  return -1; 
}

/*
This function is remove a data type in the array and return false if return is -1 or return true if return is not -1.

array is an array of any data type
N is the number of the array.
key is the data type looking for.
*/
template <class T, class T2>
bool remove(T array[], int N, const T2& key)
{
  int index = find(array, N, key);
  if(index == -1) //If the index return -1 then return false.
    {
      return false;
    }
  else //Else the index return something else to move the array to the right to remove it.
    {
      for(int j = index; j < N-1; j++) //Go through the array to move the right to remove it.
	{
	  array[j] = array[j + 1];
	}
      return true;
    }
}

#endif
