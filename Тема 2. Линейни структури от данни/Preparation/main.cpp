#define DOCTEST_CONFIG_IMPLEMENT
#include <iostream>
#include "doctest.h"

template<typename T>
struct Node {
    T data;
    Node *next;
};

int count(Node<int>* first, int x)
{
    if(first == nullptr)
    {
        return 0;
    }
    int timesFound = 0;
    while(first != nullptr)
    {
        if(first->data == x)
        {
            timesFound++;
        }
        first = first->next;
    }

    return timesFound;
}

TEST_CASE("count_shouldReturnZero_whenEmptyListAndNumber_areProvided")
{
    //given
    Node<int>* objectUnderTest = nullptr;

    //when
    int timesFive = count(objectUnderTest, 5);

    //then
    CHECK(timesFive == 0);
}

TEST_CASE("count_shouldReturnOne_whenListWithOneExactElement_isProvided")
{
    //given
    Node<int>* objectUnderTest = new Node<int>{1, nullptr};

    //when
    int timesOne = count(objectUnderTest, 1);

    //then
    CHECK(timesOne == 1);
}

Node<int>* createListFromInterval(int x, int y) {
    if(x > y) {
        return nullptr;
    }
    Node<int>* first = nullptr;
    while(x <= y) {
        first = new Node<int>{y, first};
        y--;
    }

    return first;
}


int main() {
    doctest::Context().run();
    return 0;
}