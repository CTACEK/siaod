//
// Created by CTACEK on 4/18/2022.
//
#include <iostream>


using namespace std;


template<typename Type>
class Stack {
private:
    int currcount = 0;
    int maxcount = 0;
    Type *stack;

public:
    Stack(int n);

    void push(Type item);

    void pop();

    void resize(n);
};

template<typename Type>
void Stack<Type>::push(Type item) {
    stack[currcount] = item;
    currcount++;
}

template<typename Type>
void Stack<Type>::pop() {
    Type temp = stack[currcount];
    currcount
}

template<typename Type>
Stack<Type>::Stack(int n) {
    maxcount = n;
    stack = (Type *) calloc(maxcount, sizeof(Type));

}

template<typename Type>
void Stack<Type>::resize(int n) {
    maxcount = n;
    stack = (Type *) realloc(stack, maxcount * sizeof(Type));
}

