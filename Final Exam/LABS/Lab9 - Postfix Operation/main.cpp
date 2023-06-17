#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Postfix
{
private:
    stack<int> stk;
    int perform_operation(int a, int b, char op); // since outside the class it won't be used make it private

public:
    Postfix(/* args */);

    int postfix_calculate(string expr);
};

Postfix::Postfix(/* args */)
{
}

int Postfix::perform_operation(int a, int b, char op)
{
    switch (op) // basic calculator op stands for operator and performs the operation
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        return 0;
    }
}

int Postfix::postfix_calculate(string expr)
{
    int a, b, result;
    for (int i = 0; i < expr.length(); i++)
    {
        if (isdigit(expr[i])) // if it's a digit push it into the stack  1 2 + 3 4 - * 3 / (1,2,3,4) will be in stack
        {
            stk.push(expr[i] - '0');
        }
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') // if there's an operator
        {
            b = this->stk.top();                       // top two elements will be performed by the operator
            this->stk.pop();                           // and pop it
            a = stk.top();                             // get the second element
            this->stk.pop();                           // and pop it
            result = perform_operation(a, b, expr[i]); // into another function send a,b and operator in string
            this->stk.push(result);                    // push the result into stack since it might be used after that as an operand
        }
    }
    return stk.top(); // lastly it will return the result
}

int main()
{
    Postfix x;
    string expr;
    cout << "Enter a postfix expression: ";
    getline(cin, expr);
    int result = x.postfix_calculate(expr);
    cout << "Result: " << result << endl;
    return 0;
}
