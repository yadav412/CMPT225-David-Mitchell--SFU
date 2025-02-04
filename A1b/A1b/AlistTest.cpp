//
//  Test Program for AList 
//
#include <iostream>   // for I/O facilities
using namespace std;
#include "Alist.h" //  include AList program 

int main (int argc, char * const argv[]) {

    AList<int> ls1;

    ls1.addRight(1);
    ls1.addRight(2);
    ls1.addLeft(3);
    ls1.addLeft(6);


    cout << "List contents: ";
    ls1.display();

    cout << "After removing right: ";
    ls1.removeRight();
    ls1.display();

    cout << "After removing left: ";
    ls1.removeLeft();
    ls1.display();

    cout << "Debug info: " << endl;
    ls1.ddisplay();
  
  
  cout << "Test for the clear function"<<endl;

  ls1.clear();
  cout<<"List contents:";

  ls1.display();

  cout<< "Debug info for clear function:"<<endl;
  ls1.ddisplay();


    return 0;
	
}
