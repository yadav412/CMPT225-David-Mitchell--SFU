/******************************************************************
/******************************************************************
** 
**   A Test Program for the AList Class, Assignment 1 Part B
** 
**   File: TestAddLeft.cpp
** 
**   Copyright © 2025, Yadav Singh.  All rights reserved.
**  
*******************************************************************
******************************************************************/
#include <iostream>   // for I/O facilities
using namespace std;
#include "AList.h" //  AList class declaration



int main (int argc, char * const argv[]) {

	cout<<"test the assertion by adding more than 12 elements to the array"<<endl;

	AList<int> L1 ;

	L1.addLeft(2);//1
	L1.addLeft(3);//2
	L1.addLeft(4);//3
	L1.addLeft(4);//4
	L1.addLeft(8);//5


	L1.addLeft(1);
	L1.addLeft(8);
	L1.addLeft(9);
	L1.addLeft(0);
	L1.addLeft(6);
	L1.addLeft(3);
	L1.addLeft(6);

	L1.ddisplay();
	cout<<"array has been filled to capacity"<<endl;

	L1.addLeft(8);
 

    system ("pause");
    return 0;
	
}
