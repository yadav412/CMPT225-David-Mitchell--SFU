/******************************************************************
/******************************************************************
** 
**   A Test Program for the AList Class, Assignment 1 Part B
** 
**   File: TestAddRight.cpp
** 
**   Copyright © 2025, Yadav Singh.  All rights reserved.
**  
*******************************************************************
******************************************************************/
#include <iostream>   // for I/O facilities
using namespace std;
#include "AList.h" //  AList class declaration

int main (int argc, char * const argv[]) {

cout<< "test program for addRight assertion"<<endl;
	
        // Make an int AList
	AList<int> L1 ;

	L1.addRight(2);//1
	L1.addRight(3);//2
	L1.addRight(4);//3
	L1.addRight(4);//4
	L1.addRight(8);//5


	L1.addRight(1);//6
	L1.addRight(8);//7
	L1.addRight(9);//8
	L1.addRight(0);//9
	L1.addRight(6);//10
	L1.addRight(3);//11
	L1.addRight(6);//12 (the size of the array is now 12 and the array is full)

	L1.ddisplay();
	cout<<"array has been filled to capacity"<<endl;

	L1.addRight(8);// this makes the size ==13 therefore triggers the assertion
 