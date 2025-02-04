/******************************************************************
/******************************************************************
** 
**   A Test Program for the AList Class, Assignment 1 Part B
** 
**   File: TestRemoveLeft.cpp
** 
**   Copyright © 2025, Yadav Singh.  All rights reserved.
**  
*******************************************************************
******************************************************************/
#include <iostream>   // for I/O facilities
using namespace std;
#include "AList.h" //  AList class declaration

int main (int argc, char * const argv[]) {
	cout<< "test program for removeLeft() assertion"<<endl;
	
        // Make an int AList
	AList<int> L1 ;

	L1.removeLeft();

	
	return 0;
}