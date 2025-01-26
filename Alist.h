#ifndef ALIST_H
#define ALIST_H

#include <iostream>

using namespace std;

template <typename Object>
class AList 
{
public:

    AList() // Constructor
    {
        theCapacity = 12; // Default capacity
        objects = new Object[theCapacity];
        theSize = 0;
        left = 0;  // Start of the deque
        right = 0; // End of the deque
    }

    ~AList() // Destructor
    {
        delete[] objects;
    }

    bool empty() const
    {
        return theSize == 0;
    }

    int size() const
    {
        return theSize;
    }

    void clear()
    {
        theSize = 0;
        left = 0;
        right = 1;
    }

    void addLeft(const Object& x) // Insert a new object at the left end
    {
        if (theSize == theCapacity) // Handle overflow (optional resizing logic could be added)
            throw runtime_error("Deque is full.");

        left = (left - 1 + theCapacity) % theCapacity;
        objects[left] = x;
        theSize++;
    }

    void addRight(const Object& x) // Insert a new object at the right end
    {
        if (theSize == theCapacity) // Handle overflow
            throw runtime_error("Deque is full.");

        objects[right] = x;
        right = (right + 1) % theCapacity;
        theSize++;
    }

    Object removeLeft() // Remove and return the object at the left end
    {
        if (empty())
            throw runtime_error("Cannot remove from an empty deque.");

        Object temp = objects[left];
        left = (left + 1) % theCapacity;
        theSize--;
        return temp;
    }

    Object removeRight() // Remove and return the object at the right end
    {
        if (empty())
            throw runtime_error("Cannot remove from an empty deque.");

        right = (right - 1 + theCapacity) % theCapacity;
        Object temp = objects[right];
        theSize--;
        return temp;
    }

    void display() const // Print out the contents of the deque
    {
        for (int i = 0; i < theSize; i++)// loop through the values 

        {
            int index = (left + i) % theCapacity; //index adjust
            cout << objects[index] << " ";
        }
        cout << endl;
    }

    void ddisplay() const // Print out internals of the array for debugging// the xray 
    {
        cout << "Capacity: " << theCapacity << ", Size: " << theSize
             << ", Left: " << left << ", Right: " << right << endl;
        cout << "Contents: ";
        for (int i = 0; i < theCapacity; i++)
        {
            cout << objects[i] << " ";
        }
        cout << endl;
    }

private:

    int theSize;
    int left;
    int right;
    int theCapacity;
    Object* objects;
};

#endif
