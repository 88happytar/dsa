#include<iostream>
#include<cmath>
#include<stack>
using namespace std;

// The function calculate_Postfix returns the final answer of the expression after calculation
int calculatePostfix(string post_exp)
{
    stack <int> stack;
    int len = post_exp.length();

    // loop to iterate through the expression
    for (int i = 0; i < len; i++)
    {
        // if the character is an operand we push it in the stack
        // we have considered single digits only here
        if ( post_exp[i] >= '0' &&  post_exp[i] <= '9')
        {
            stack.push( post_exp[i] - '0');
        }
        // if the character is an operator we enter else block
        else
        {
            // we pop the top two elements from the stack and save them in two integers
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            
            //performing the operation on the operands
            switch (post_exp[i])
            {
                case '+': // addition
                          stack.push(b + a);
                          break;
                case '-': // subtraction
                          stack.push(b - a);
                          break;
                case '*': // multiplication
                          stack.push(b * a);
                          break;
                case '/': // division
                          stack.push(b / a);
                          break;
                case '^': // exponent
                          stack.push(pow(b,a));
                          break;
            }
        }
    }
    //returning the calculated result
    return stack.top();
}

int main()
{
    //we save the postfix expression to calculate in postfix_expression string
    //string postfixExpression = "59+33^4*6/-"; //-4
    string postfixExpression = "53+62/*35*+";  //39
    cout<<"The answer after calculating the postfix expression is : ";
    cout<<calculatePostfix(postfixExpression);
    return 0;
}

