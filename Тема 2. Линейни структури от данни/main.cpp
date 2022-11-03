#include <iostream>
#include <cassert>
#include <vector>

template<typename T>
struct Node {
    T data;
    Node<T> *next;
};

template<typename T>
Node<T> *pushBack(Node<T> *&first, const T newData) {
    if (first == nullptr) {
        first = new Node<T>{newData, nullptr};
        return first;
    }

    Node<T> *current = first;
    while (current->next != nullptr) {
        current = current->next;
    }

    assert(current->next == nullptr);
    current->next = new Node<T>{newData, nullptr};

    return first;
}

template<typename T>
Node<T> *get_ith(Node<T> *first, int n) {

    assert(first != nullptr);

    while (first != nullptr || n != 0) {
        first = first->next;
        n--;
    }
    return first;
}

template<typename T>
Node<T> *removeALl(Node<T> *first, const T el) {

    assert(first != nullptr);

    Node<T> *curr = first;
    Node<T> *prev = first;

    if (first->data == el) {
        first = first->next;
        curr = curr->next;
    }

    while (curr->next != nullptr) {
        if (curr->data == el) {
            prev->next = curr->next;
            curr = curr->next;
            continue;
        }
        prev = curr;
        curr = curr->next;
    }
    if (curr->data == el) {
        prev = nullptr;
    }
    return first;
}

template<typename T>
void print(Node<T> *first) {
    while (first != nullptr) {
        std::cout << first->data << "->";
        first = first->next;
    }
    std::cout << "nullptr" << std::endl;
}

template<typename T>
Node<T> *removeAll(Node<T> *&first, const T el) {
    if (first == nullptr) {
        return first;
    }

    Node<T> *current = first;
    while (current->data == el) {
        Node<T> *save = current;
        current = current->next;
        delete save;
    }
    first = current;
    Node<T>* prev = current;
    current = current->next;

    while (current->next != nullptr) {
        if(current->data == el) {
            prev->next = current->next;
            delete[] current;
            current = prev->next;
        }
        prev = current;
        current = current->next;
    }

    if(current->data == el) {
        delete[] current;
        prev->next = nullptr;
    }
}

int main() {
    Node<int> *list = new Node<int>{1,
                                    new Node<int>{1,
                                                  new Node<int>{5,
                                                                new Node<int>{2,
                                                                              new Node<int>{1, nullptr}}}}};
    print(list);
    removeAll(list, 1);
    print(list);
    return 0;
}
