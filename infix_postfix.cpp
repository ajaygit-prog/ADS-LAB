#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

int main() {
    string infix, postfix = "";
    stack<char> st;

    cout << "Enter infix expression: ";
    cin >> infix;

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else {
            while (!st.empty() && st.top() != '(' &&
                  (precedence(st.top()) > precedence(c) ||
                  (precedence(st.top()) == precedence(c) && c != '^'))) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    cout << "Postfix Expression: " << postfix;

    return 0;
}