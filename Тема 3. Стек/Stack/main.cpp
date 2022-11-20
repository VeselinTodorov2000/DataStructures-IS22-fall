#define DOCTEST_CONFIG_IMPLEMENT

#include "doctest.h"
#include "Stack.h"

TEST_CASE("push_shouldHaveThrowException_whenCapacityIsReached"){
    Stack<int> stack(0);

    CHECK_THROWS(stack.push(1));
}

TEST_CASE("push_shouldHaveOneElement_whenNewElementIsPushedInEmptyStack"){
    Stack<int> stack(4);

    stack.push(1);

    CHECK(stack.size() == 1);
}

TEST_CASE("pop_shouldRemoveElement_whenStack_isNotEmpty") {
    Stack<int> stack(4);
    stack.push(1);
    stack.push(2);
    stack.push(3);

    stack.pop();

    CHECK(stack.size() == 2);
}

TEST_CASE("pop_shouldNotRemoveElement_whenStack_isEmpty") {
    Stack<int> stack(4);

    CHECK_THROWS(stack.pop());
}

TEST_CASE("top_shouldNotReturnElement_whenStack_isEmpty") {
    Stack<int> stack(4);

    CHECK_THROWS(stack.top());
}

TEST_CASE("top_shouldReturnLastElement_whenStack_isNotEmpty") {
    Stack<int> stack(4);
    stack.push(1);
    stack.push(2);
    stack.push(3);

    int result = stack.top();

    CHECK(result == 3);
}

int main() {
    doctest::Context().run();
    return 0;
}
