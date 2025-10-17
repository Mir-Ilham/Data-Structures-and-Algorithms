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

string postfixToInfix(string postfix) {
    stack<string> st;

    for (char c : postfix) {
        if (isChar(c)) {
            st.push(string(1, c));
        } else {
            string exp2 = st.top();
            st.pop();
            string exp1 = st.top();
            st.pop();
            exp1 = '(' + exp1 + c + exp2 + ')';
            st.push(exp1);
        }
    }
    return st.top();
}

string prefixToInfix(string prefix) {
    stack<string> st;

    for (int i = prefix.size() - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isChar(c)) {
            st.push(string(1, c));
        } else {
            string exp1 = st.top();
            st.pop();
            string exp2 = st.top();
            st.pop();
            exp1 = '(' + exp1 + c + exp2 + ')';
            st.push(exp1);
        }
    }
    return st.top();
}

string postfixToPrefix(string postfix) {
    stack<string> st;

    for (char c : postfix) {
        if (isChar(c)) {
            st.push(string(1, c));
        } else {
            string exp2 = st.top();
            st.pop();
            string exp1 = st.top();
            st.pop();
            exp1 = c + exp1 + exp2;
            st.push(exp1);
        }
    }
    return st.top(); 
}

string prefixToPostfix(string prefix) {
    stack<string> st;

    for (int i = prefix.size() - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isChar(c)) {
            st.push(string(1, c));
        } else {
            string exp1 = st.top();
            st.pop();
            string exp2 = st.top();
            st.pop();
            exp1 = exp1 + exp2 + c;
            st.push(exp1);
        }
    }
    return st.top();
}

int main() {
    /*
        Function documentation:
        
        1. string infixToPostfix(string infix) 
            -> Convert an infix expression to postfix using stack

        2. string infixToPrefix(string infix)
            -> Convert an infix expression to prefix using stack

        3. string postfixToInfix(string postfix)
            -> Convert a postfix expression to infix using stack

        4. string prefixToInfix(string prefix)
            -> Convert a prefix expression to infix using stack

        5. string postfixToPrefix(string postfix)
            -> Convert a postfix expression to prefix using stack

        6. string prefixToPostfix(string prefix)
            -> Convert a prefix expression to postfix using stack
    */

    file();

    priority['^'] = 3;
    priority['*'] = 2;
    priority['/'] = 2;
    priority['+'] = 1;
    priority['-'] = 1;


    string infix;
    cin >> infix;

    string postfix = infixToPostfix(infix);
    string prefix = infixToPrefix(infix);

    cout << "Postfix: " << postfix << endl;
    cout << "Prefix: " << prefix << endl;

    cout << "Infix from postfix: " << postfixToInfix(postfix) << endl;
    cout << "Infix from prefix: " << prefixToInfix(prefix) << endl;

    cout << "Prefix from postfix: " << postfixToPrefix(postfix) << endl;
    cout << "Postfix from prefix: " << prefixToPostfix(prefix) << endl;

    return 0;
}