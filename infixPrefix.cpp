#include <iostream>
#include <stack>
#include <string>

using namespace std;

int priority (char alpha) {
    if(alpha == '+' || alpha == '-')
        return 1;

    if(alpha == '*' || alpha == '/')
        return 2;

    if(alpha == '^')
        return 3;

    return 0;
}

string convertToPrefix(string infix)
{
    int i = 0;
    string prefix = "";
    stack<char> s;

    while(infix[i] != '\0')
    {
        if (isalpha(infix[i]))
        {
            prefix = infix[i] + prefix;
            i++;
        }
        else if (infix[i] == '(')
        {
            s.push(infix[i]);
            i++;
        }
        else if (infix[i] == ')')
        {
            while(s.top() != '(')
            {
                prefix = s.top() + prefix;
                s.pop();
            }
            s.pop();
            i++;
        }
        else
        {
            while(!s.empty() && priority(infix[i]) <= priority(s.top()) && s.top() != '(')
            {
                prefix = s.top() + prefix;
                s.pop();
            }
            s.push(infix[i]);
            i++;
        }
    }
    while(!s.empty())
    {
        prefix = s.top() + prefix;
        s.pop();
    }

    return prefix;
}

int main()
{
    string prefix;
    string infix;
    cout << "Enter the Infix notation to be converted: ";
    cin >> infix;
    prefix = convertToPrefix(infix);
    cout << "Prefix is: " << prefix << endl;
    
    return 0;
}