#pragma once

#include <cstddef> // для std::size_t

class StaticStack {
private:
    static const std::size_t CAPACITY = 5; 
    int data[CAPACITY];                   
    std::size_t count;                     

public:
    StaticStack();
    void push(int value);
    void pop();
    int& top();
    const int& top() const;
    bool isEmpty() const;
    bool isFull() const;
    std::size_t size() const;
    std::size_t capacity() const;
    void clear();
};