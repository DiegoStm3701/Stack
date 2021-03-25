#include "Stack.h"
#include <vector>
using namespace std;
using namespace cop4530;

template <typename T>
Stack<T>::Stack(){
}

//~Stack (): destructor.
template <typename T>
Stack<T>::~Stack(){
    clear();
} 

//Stack (const Stack<T>&): copy constructor.   
template <typename T>
Stack<T>::Stack(const Stack<T>&a){
    for(int i = 0; i <= a.container.size(); i++){
        container.push_back(a.container[i]);
    }
}

//Stack(Stack<T> &&): move constructor.
template <typename T>
Stack<T>::Stack(Stack<T> &&a){
    for(int i = 0; i <= a.container.size(); i++){
        container.push_back(move(a.container[i]));
    }
}

//Stack<T>& operator= (const Stack <T>&): copy assignment operator=.
template <typename T>
typename Stack<T>::Stack& Stack<T>::operator= (const Stack <T>&a){
    clear();
    for(int i = 0; i <= a.container.size(); i++){
        container.push_back(a.container[i]);
    }
}


//Stack<T> & operator=(Stack<T> &&): move assignment operator=
template <typename T>
typename Stack<T>::Stack & Stack<T>::operator=(Stack <T>&&a){
    clear();
    for(int i = 0; i <= a.container.size(); i++){
        container.push_back(move(a.container[i]));
    }
}

//bool empty() const: returns true if the Stack contains no elements, and false otherwise.
template <typename T>
bool Stack<T>::empty() const{
    return container.empty();
}

//void clear(): delete all elements from the stack.
template <typename T>
void Stack<T>::clear(){
    container.clear();
}

//void push(const T& x): adds  x  to the Stack.   copy version.
template <typename T>
void Stack<T>::push(const T& x){
    container.push_back(x);
}

//void push(T && x): adds x to the Stack. move version.
template <typename T>
void Stack<T>::push(T && x){
    container.push_back(move(x));
}

//void pop(): removes and discards the most recently added element of the Stack.  
template <typename T>
void Stack<T>::pop(){
    container.pop_back();
}

//T& top(): mutator that returns a reference to the most recently added element of the Stack.  
template <typename T>
T& Stack<T>::top(){
    return container.back();
}

//const T& top() const: accessor that returns the most recently added element of the Stack.
template <typename T>
const T& Stack<T>::top() const{
    return container.back();
}

//int size() const: returns the number of elements stored in the Stack.
template <typename T>
int Stack<T>::size(){
    return container.size();
}

//void print(std::ostream& os, char ofc = ' ') const: print elements of Stack to ostream os. ofc is the separator between 
//elements in the stack when they are printed out. Note that print() prints elements in the opposite order of the Stack 
//(that is, the oldest element should be printed first).
template <typename T>
void Stack<T>::print(std::ostream& os, char ofc) const{
for(int i = 0; i < container.size(); i++){
    os << container[i] << ofc;
}
}

//std::ostream& operator<< (std::ostream& os, const Stack<T>& a): invokes the print() method to print the Stack<T> a in the specified 
//ostream   
template <typename T>
std::ostream& operator<< (std::ostream& os, const Stack<T>& a){
    a.print(cout);
    return os;
}
//bool operator== (const Stack<T>&, const Stack <T>&): returns true if the two compared Stacks have the same elements, in the same 
//order.
template <typename T>
bool operator== (const Stack<T>&a, const Stack <T>&b){
if(a.container.size() != b.container.size()){
    return false;
}
for(int i = 0; i < a.container.size(); i++){
    if(a.container[i] != b.container[i]){
        return false;
    }
}
return true;
}

//bool operator!= (const Stack<T>&, const Stack <T>&): opposite of operator==().
template <typename T>
bool operator!= (const Stack<T>&a, const Stack <T>&b){
if(a.container.size() != b.container.size()){
    return true;
}
for(int i = 0; i < a.container.size(); i++){
    if(a.container[i] != b.container[i]){
        return true;
    }
}
return false;
}

//bool operator<=(const Stack<T>& a, const Stack <T>& b): returns true if every element in Stack a is smaller than or equal to the 
//corresponding element of Statck b, i.e., if repeatedly invoking top() and pop() on both a and b,  we will generate a sequence of 
//elements a_i from a and b_i from b, and for every i,  a_i <= b_i, until a is empty. 
template <typename T>
bool operator<= (const Stack<T>&a, const Stack <T>&b){
    if(a.size() > b.size()){
        return false;
    }
    for(int i = 0; i < a.size(); i++){
        if(a.container[i] > b.container[i]){
            return false;
        }
    }
    return true;
} 