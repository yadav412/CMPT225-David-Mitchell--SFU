/******************************************************************

** 
**   A Test Program for the AList Class, Assignment 1 Part B
** 
**   File: TestAddLeft.cpp
** 301634896  ysa306
**   Copyright © 2025, Yadav Singh.  All rights reserved.
**  
*******************************************************************
******************************************************************/
#include <iostream>   // for I/O facilities

#include <vector>
#include <string>
#include <utility> 
using namespace std;
#include "ans3.h"
 //  AList class declaration



int main() {
    IndPQ pq;

    pq.insert("task1", 10);
    pq.insert("task2", 5);
    pq.insert("task3", 20);
    
    pq.display();

    std::cout << "Minimum Task: " << pq.getMin() << std::endl;
    
    
    pq.ddisplay();

    pq.updatePriority("task1", 3);
    std::cout << "Minimum Task after update: " << pq.getMin() << std::endl;

    pq.deleteMin();
    std::cout << "Minimum Task after delete: " << pq.getMin() << std::endl;

    std::cout << "Is the queue empty? " << (pq.isEmpty() ? "Yes" : "No") << std::endl;

    pq.remove("task3");
    pq.clear();
    std::cout << "Is the queue empty after clear? " << (pq.isEmpty() ? "Yes" : "No") << std::endl;
    
    pq.display();

    return 0;
}
