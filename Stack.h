#ifndef DL_STACK_H
#define DL_STACK_H
#include <vector>
#include <iostream>
using namespace std;

namespace cop4530{
    template <typename T>
    class Stack{
        private:


    
        public:
        vector <T> container;
        //Stack(): zero-argument constructor. 
        Stack();

        //~Stack (): destructor.
        ~Stack(); 

        //Stack (const Stack<T>&): copy constructor.   
        Stack (const Stack<T>&);

        //Stack(Stack<T> &&): move constructor.
        Stack(Stack<T> &&);

        //Stack<T>& operator= (const Stack <T>&): copy assignment operator=.
        Stack<T>& operator= (const Stack <T>&);

        //Stack<T> & operator=(Stack<T> &&): move assignment operator=
        Stack<T> & operator=(Stack<T> &&);

        //bool empty() const: returns true if the Stack contains no elements, and false otherwise.
        bool empty() const;  

        //void clear(): delete all elements from the stack.
        void clear();

        //void push(const T& x): adds  x  to the Stack.   copy version.
        void push(const T& x);

        //void push(T && x): adds x to the Stack. move version.
        void push(T && x);

        //void pop(): removes and discards the most recently added element of the Stack.  
        void pop();

        //T& top(): mutator that returns a reference to the most recently added element of the Stack.  
        T& top();

        //const T& top() const: accessor that returns the most recently added element of the Stack.  
        const T& top() const;

        //int size() const: returns the number of elements stored in the Stack.
        int size();

        //void print(std::ostream& os, char ofc = ' ') const: print elements of Stack to ostream os. ofc is the separator between 
        //elements in the stack when they are printed out. Note that print() prints elements in the opposite order of the Stack 
        //(that is, the oldest element should be printed first).
        void print(std::ostream& os, char ofc = ' ') const;
        
        
};
//std::ostream& operator<< (std::ostream& os, const Stack<T>& a): invokes the print() method to print the Stack<T> a in the specified 
//ostream   
template <typename T>
	std::ostream & operator<<(std::ostream &os, const Stack<T> &a);

//bool operator== (const Stack<T>&, const Stack <T>&): returns true if the two compared Stacks have the same elements, in the same 
//order.
template <typename T>
bool operator== (const Stack<T>&, const Stack <T>&);

// bool operator!= (const Stack<T>&, const Stack <T>&): opposite of operator==().
template <typename T>
bool operator!= (const Stack<T>&, const Stack <T>&);

//bool operator<=(const Stack<T>& a, const Stack <T>& b): returns true if every element in Stack a is smaller than or equal to the 
//corresponding element of Statck b, i.e., if repeatedly invoking top() and pop() on both a and b,  we will generate a sequence of 
//elements a_i from a and b_i from b, and for every i,  a_i <= b_i, until a is empty.
template <typename T>    
bool operator<=(const Stack<T>& a, const Stack <T>& b);


#include "Stack.hpp"
}

#endif