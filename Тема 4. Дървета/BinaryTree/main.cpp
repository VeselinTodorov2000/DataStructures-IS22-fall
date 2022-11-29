#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <iostream>
#include "BTree.h"

TEST_CASE("Add element test")
{
    BTree<int> t;
    t.pushAt(1, "");
    t.pushAt(2, "L");
    t.pushAt(3, "R");
    t.pushAt(4, "LL");
    t.pushAt(5, "LR");
    t.pushAt(6, "RL");
    t.pushAt(7, "RR");

    CHECK(t.get("LL") == 4);
    CHECK(t.get("RL") == 6);
}


TEST_CASE("Copy tree")
{
    BTree<int> t;
    t.pushAt(1, "");
    t.pushAt(2, "L");
    t.pushAt(3, "R");
    t.pushAt(4, "LL");
    t.pushAt(5, "LR");
    t.pushAt(6, "RL");
    t.pushAt(7, "RR");

    BTree<int> t1(t);
    CHECK(t1.get("LL") == 4);
    CHECK(t1.get("RL") == 6);

    BTree<int> t2;
    t2 = t1;

    CHECK(t2.get("LL") == 4);
    CHECK(t2.get("RL") == 6);

    //t2.print();
}

TEST_CASE("Counting")
{
    BTree<int> t;
    t.pushAt(1, "");
    t.pushAt(2, "L");
    t.pushAt(3, "R");
    t.pushAt(4, "LL");
    t.pushAt(5, "LR");
    t.pushAt(6, "RL");
    t.pushAt(7, "RR");

    CHECK(t.count() == 7);

    t.pushAt(10, "LLL");
    CHECK(t.count() == 8);
}

TEST_CASE("Counting evens")
{
    BTree<int> t;
    t.pushAt(1, "");
    t.pushAt(2, "L");
    t.pushAt(3, "R");
    t.pushAt(4, "LL");
    t.pushAt(5, "LR");
    t.pushAt(6, "RL");
    t.pushAt(7, "RR");

    CHECK(t.countEvens() == 3);

    t.pushAt(10, "LLL");
    CHECK(t.countEvens() == 4);
}


TEST_CASE("Functional")
{
    BTree<int> t;
    t.pushAt(1, "");
    t.pushAt(2, "L");
    t.pushAt(3, "R");
    t.pushAt(4, "LL");
    t.pushAt(5, "LR");
    t.pushAt(6, "RL");
    t.pushAt(7, "RR");

    CHECK(t.searchCount([](const int& num){return num%2==0;}) == 3);

    t.pushAt(8, "LLL");

    CHECK(t.searchCount([](const int& num){return num%2==0;}) == 4);
}

TEST_CASE("Height")
{
    BTree<int> t;
    t.pushAt(1, "");
    t.pushAt(2, "L");
    t.pushAt(3, "R");
    t.pushAt(4, "LL");
    t.pushAt(5, "LR");
    t.pushAt(6, "RL");
    t.pushAt(7, "RR");

    CHECK(t.height() == 3);

    t.pushAt(8, "LLL");

    CHECK(t.height() == 4);
}

TEST_CASE("Leaves counter")
{
    BTree<int> t;
    t.pushAt(1, "");
    t.pushAt(2, "L");
    t.pushAt(3, "R");
    t.pushAt(4, "LL");
    t.pushAt(5, "LR");
    t.pushAt(6, "RL");
    t.pushAt(7, "RR");

    CHECK(t.countLeaves() == 4);

    t.pushAt(8, "LLL");

    CHECK(t.countLeaves() == 4);
}

TEST_CASE("Max")
{
    BTree<int> t;
    t.pushAt(1, "");
    t.pushAt(2, "L");
    t.pushAt(3, "R");
    t.pushAt(4, "LL");
    t.pushAt(5, "LR");
    t.pushAt(6, "RL");
    t.pushAt(7, "RR");

    CHECK(t.maxLeaf() == 7);

    t.pushAt(10, "LLL");

    CHECK(t.maxLeaf() == 10);
}
int main()
{
    doctest::Context().run();
}