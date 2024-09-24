//***************************************************************************
//
// Syed Ali Quadri
// Z1972275
// CSCI 340 - PE1
// Assignment 04 - Stacks
// Due Date - 09/24/2024
// I certify that this is my own work and where appropriate an extension
// of the starter code provided for the assignment.
//
//***************************************************************************

#ifndef STACK_H
#define STACK_H
#include <queue> //include queue to to implement the stack

template<typename T>
class Stack
{
private:
    std::queue<T> q1;	// These queues are where the stack's elements 
    std::queue<T> q2;	// are to be saved.

public:
/**
* checks if the stack is empty
*
* @return true if q1 is empty and false if not
*/
bool empty() const;

/**
 * checks the size of the stack
 *
 * @return the size of the stack in integer value
 */
int size() const;

/**
 * gives the top recent number
 *
 * @return the most recent element in the stack
 */
const T& top();

/**
 * adds new element to stack
 *
 * This method uses multiple queue 1 and 2 where val is pushed to q2,
 * from there all elements from q1 are moved to q2 then the queues are swapped
 *
 * @param val the element that will be added to stack
 */
void push(const T &val);

/**
 * Removes top element from stack
 */
void pop();
};


// Note that the members of a template go into a .h file since 
// they are not compiled directly into a .o file like the members 
// of regular/non-template classes.




// Place your Stack class member implementations here.

template<typename T>
bool Stack<T>::empty() const
{
    return q1.empty(); //check if stack is empty
}

template<typename T>
int Stack<T>::size() const
{
    return int(q1.size()); //returns size of stack
}

template<typename T>
const T& Stack<T>::top()
{
    return q1.front(); //returns first element of q1
}

template<typename T>
void Stack<T>::push(const T &val)
{
    q2.push(val); //push new element to q2

    while (!q1.empty())
    {
        q2.push(q1.front()); //transfer elements from q1 to q2
        q1.pop();
    }

    q1.swap(q2); //swap q2 back to q1
}

template<typename T>
void Stack<T>::pop()
{
    q1.pop(); //delete most recent element
}



#endif // STACK_H
