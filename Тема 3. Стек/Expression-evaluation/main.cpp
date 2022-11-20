#include <iostream>
#include <stack>

//task 1
int convertToBinary(int number) {
    std::stack<int> bits;
    while(number != 0) {
        bits.push(number % 2);
        number /= 2;
    }

    int binaryNumber = 0;
    while(!bits.empty()) {
        binaryNumber = binaryNumber * 10 + bits.top();
        bits.pop();
    }

    return binaryNumber;
}

//task 2
bool rightBrackets(const std::string& expression) {
    std::stack<char> brackets;

    for(int i = 0; i < expression.size(); i++) {
        if(expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            brackets.push(expression[i]);
        }
        else {
            if(expression[i] == ')') {
                if(brackets.top() == '(') {
                    brackets.pop();
                } else {
                    return false;
                }
            } else if(expression[i] == ']') {
                if(brackets.top() == '[') {
                    brackets.pop();
                } else {
                    return false;
                }
            } else if(expression[i] == '}') {
                if(brackets.top() == '{') {
                    brackets.pop();
                } else {
                    return false;
                }
            }
        }
    }

    return brackets.empty();
}
std::string mirror(std::string& str)
{
    std::stack<char> characters;
    for(int i = 0; i < str.length();i++)
    {
        characters.push(str[i]);
    }

    while(!characters.empty())
    {
        str += characters.top();
        characters.pop();
    }
    return str;
}
int main() {
    //std::cout << std::boolalpha << rightBrackets("(({[][]([])}{}[]))") << std::endl;
    std::string str="12344";
    std::cout<<mirror(str);
    return 0;
}
