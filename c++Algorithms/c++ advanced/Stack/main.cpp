//Author: Chaim Fishman
//208509349
//the algorithm for infix to postfix was taken from online sources since the 
//the algorithm that was given on the hw was not 
#include <iostream>
#include "StackList.h"
using namespace std;


int preced(char ch); 
string infixToPostfix(string infix);
float calcPostfix(string postfix)
{
    float num1, num2;
    StackList calc;
    StackList intial;
    string::iterator it;
    char ita;
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        ita = postfix[i];
        if (ita >= '0' && ita <= '9')
            intial.push(ita);
        else if (ita == '+')
        {
            num2 = calc.pop();
            num1 = calc.pop();
            calc.push(num1 + num2);
        }
        else if (ita == '-')
        {
            num2 = calc.pop();
            num1 = calc.pop();
            calc.push(num1 - num2);
        }
        else if (ita == '*')
        {
            num2 = calc.pop();
            num1 = calc.pop();
            calc.push(num1 * num2);
        }
        else if (ita == '/')
        {
            num2 = calc.pop();
            num1 = calc.pop();
            calc.push(num1 / num2);
        }
        else if (ita == ' ' && !intial.isEmpty())//get number and store
        {
            int number = 0;
            int i = 1;

            while (!intial.isEmpty())
            {
                number += ((intial.pop()-48) * i);
                i *= 10;
            }
            calc.push(number);
        }
    }
    return calc.pop();
}


int main()
{
    string exp;
    cout << "enter an infix expression as a string" << endl;
    cin >> exp;
    string postfix = infixToPostfix(exp);
    cout << postfix << endl;
    cout << calcPostfix(postfix) << endl;
    return 0;
}








string infixToPostfix(string infix) {
    StackList stk;
    stk.push('#');               //add some extra character to avoid underflow
    string postfix = "";         //initially the postfix string is empty
    char it;

    for (int i= 0; infix[i] != '\0'; i++) {
        it = infix[i];
        if (it >= '0' && it <= '9')
            postfix += it;      //add to postfix when number
        else
        {
            postfix += ' ';
            if (it == '(')
                stk.push('(');
            else if (it == ')') {
                while (stk.top() != '#' && stk.top() != '(') {
                    postfix += stk.top(); //store and pop until ( has found
                    stk.pop();
                }
                stk.pop();          //remove the '(' from stack
            }
            else {
                if (preced(it) > preced(stk.top()))
                    stk.push(it); //push if precedence is high
               else {
                    while (stk.top() != '#' && preced(it) <= preced(stk.top())) {
                        postfix += stk.top();        //store and pop until higher precedence is found
                        stk.pop();
                    }
                    stk.push(it);
                }
            }
        }
    }

    while (stk.top() != '#') {
        postfix += ' ';
        postfix += stk.top();        //store and pop until stack is not empty.
        stk.pop();
    }

    return postfix;
}


int preced(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;              //Precedence of + or - is 1
    }
    else if (ch == '*' || ch == '/') {
        return 2;            //Precedence of * or / is 2
    }
    else {
        return 0;
    }
}