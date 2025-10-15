#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

map<char, int> priority;

bool isChar(char c) {
    return ('A' <= c and c <= 'Z') 
        or ('a' <= c and c <= 'z') 
        or ('0' <= c and c <= '9');
}

string infixToPostfix(string infix) {
    stack<char> st;
    
    string postfix;

    for (char c : infix) {
        if (isChar(c)) {
            postfix.push_back(c);
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() and st.top() != '(') {
                postfix.push_back(st.top());
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() and st.top() != '(' and priority[st.top()] >= priority[c]) {
                postfix.push_back(st.top());
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        postfix.push_back(st.top());
        st.pop();
    }

    return postfix;
}

string infixToPrefix(string infix) {
    stack<char> st;

    reverse(infix.begin(), infix.end());
    
    string prefix;

    for (char c : infix) {
        if (isChar(c)) {
            prefix.push_back(c);
        } else if (c == ')') {
            st.push(c);
        } else if (c == '(') {
            while (!st.empty() and st.top() != ')') {
                prefix.push_back(st.top());
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() and st.top() != ')'
                    and ((priority[c] < priority[st.top()]) 
                    or (priority[c] == priority[st.top()] and priority[c] == 3))) {
                prefix.push_back(st.top());
                st.pop();   
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        prefix.push_back(st.top());
        st.pop();
    }

    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main() {
    /*
        Function documentation:
        
        1. string infixToPostfix(string &infix) 
            -> Convert an infix expression to postfix using stack

        2. string infixToPrefix(string &infix)
            -> Convert an infix expression to prefix using stack
    */

    file();

    priority['^'] = 3;
    priority['*'] = 2;
    priority['/'] = 2;
    priority['+'] = 1;
    priority['-'] = 1;


    string infix;
    cin >> infix;

    cout << "Postfix: " << infixToPostfix(infix) << endl;
    cout << "Prefix: " << infixToPrefix(infix) << endl;


    return 0;
}