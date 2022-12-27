//Parenthesis Matching
#include <iostream>
#include <stack>
using namespace std;

int isBalanced(string str)
{
    stack<char> aStack;
    int hasChar = 0; //hasChar is an arbitrary variable

    for (int i=0; i<str.length(); i++)
    //for length of the string calculated by number of letters
    {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(') {
            //push function to enter terms in a stack
            aStack.push(str[i]);
            hasChar = 1;
        }
        if (!aStack.empty()) {
            if (str[i] == '}') {
                if (aStack.top() == '{')
                // top of the stack
                {
                    aStack.pop();
                    //pop function to delete terms from the top of array
                    continue;
                }
                else
                    break;
            }
            if (str[i] == ']') {
                if (aStack.top() == '[') {
                    aStack.pop();
                    continue;
                }
                else
                    break;
            }
            if (str[i] == ')') {
                if (aStack.top() == '(') {
                    aStack.pop();
                    continue;
                }
                else
                    break;
            }
        }
        else {
            break;
        }
    }

    if (aStack.empty() && hasChar == 1)
        return 1;
    else
        return 0;
}

int main()
{
    cout << "++++++++++++++ isBalanced ++++++++++++++" << endl;
    //string str = "((a+b)*(c-d))";
    //string str = "(((a+b)*(c-d))";
    //string str = "{((a+b]*[c-d])/e}";
    string str = "{([a+b]*[c-d])/e}";

    int x = isBalanced(str);
    if(x==1)
        cout << "Parenthesis is matching " <<endl;
    else
        cout << "Parenthesis error "<<endl;

    return 0;
}