#include <string>
#include <iostream>
#include <stack>

int getSum(const std::string& expression) //предварително трябва да се провери дали въведения израз е коректно скобуван (задача 1, седмица 4)
{
    std::stack<int> stackInt; //ще запазва само числата
    std::stack<char> stackChar; //ще запазва скобите и операциите
    unsigned size = expression.length();
    int number = 0, firstNumber = 0, secondNumber = 0;
    char operation;

    for (unsigned i = 0; i < size; ++i)
    {
        if (expression[i] >= '0' && expression[i] <= '9') //числото може да е многоцифрено, затова трябва да се вземат всички цифри
        {
            number = expression[i] - '0';
            while (expression[i + 1] >= '0' && expression[i + 1] <= '9')
            {
                number *= 10;
                number += expression[i + 1] - '0';
                ++i;
            }
            stackInt.push(number);
            number = 0;
        }
        else if (expression[i] == '(' || expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
        {
            stackChar.push(expression[i]);
        }
        else if (expression[i] == ')')
        {
            if (!stackInt.empty() && !stackChar.empty())
            {
                secondNumber = stackInt.top(); //взима най-горното число
                stackInt.pop();
                operation = stackChar.top();//взима операцията
                stackChar.pop(); //премахва операцията
                stackChar.pop(); //премахва отварящата скоба
                //не може да се предвиди случая ако в израза има отрицателно число ((-15) + 7*(3 + 1)), винаги ще търси второто число към операцията
                firstNumber = stackInt.top();
                stackInt.pop();

                switch (operation)
                {
                    case '+': stackInt.push(firstNumber + secondNumber); break;
                    case '-': stackInt.push(firstNumber - secondNumber); break;
                    case '*': stackInt.push(firstNumber * secondNumber); break;
                    case '/':
                        if (secondNumber == 0)
                        {
                            std::cout << "Wrong number 0\n";
                            return -1;
                        }
                        stackInt.push(firstNumber / secondNumber); break;
                }
            }
        }
        //ако срещне някъде друг символ, който не е проверен във if else операторите, то ще го пропусне и ще премине към следващ елемент от стринга
    }

    return stackInt.top(); //по този начин само показвам най-горния елемент от стека, но не го изтривам (можете да си създадете променлива, в която да запазите стойността връщана от top и да премахнете с pop елемента, в момента аз разчитам, че деструктора ще освободи паметта)
}

int main() {
    std::cout << getSum("(31 + (10 * (5 + 3)))") << std::endl;
    return 0;
}