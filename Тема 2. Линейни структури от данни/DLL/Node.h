#pragma once

template<typename T>
struct Node
    {
        Node* prev;
        Node* next;
        T data;

        Node(T _data, Node* _prev = nullptr, Node* _next = nullptr)
        {
            this->data = _data;
            this->prev = _prev;
            this->next = _next;
        }
    };