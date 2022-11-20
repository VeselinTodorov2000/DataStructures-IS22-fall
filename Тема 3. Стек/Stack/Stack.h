//
// Created by VeselinFMI on 11/10/2022.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H
#include <vector>
#include <exception>

template <typename T>
class Stack {
private:
    std::vector<T> data;
    std::size_t capacity;

public:
    Stack() {
        capacity = 8;
    }

    Stack(const std::size_t& capacity) {
        this->capacity = capacity;
    }

    Stack(const Stack& other) {
        for (int i = 0; i < other.data.size(); ++i) {
            this->data[i] = other.data[i];
        }
        this->capacity = other.capacity;
    }

    Stack<T>& operator=(const Stack& other) {
        if(this != &other) {
            for (int i = 0; i < other.data.size(); ++i) {
                this->data[i] = other.data[i];
            }
            this->capacity = other.capacity;
        }
    }

    T& top() {
        if(size() == 0) {
            throw new std::exception();
        }
        return data[data.size() - 1];
    }

    bool empty() const {
        return size() == 0;
    }

    std::size_t size() const {
        return this->data.size();
    }

    void push(const T& value) {
        if(size() == capacity) {
            throw new std::exception();
        }
        data.push_back(value);
    }

    void pop() {
        if(size() == 0) {
            throw new std::exception();
        }
        data.pop_back();
    }
};


#endif //STACK_STACK_H
