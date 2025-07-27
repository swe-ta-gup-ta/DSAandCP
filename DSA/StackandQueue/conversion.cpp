#include<bits/stdc++.h>

using namespace std;

int prec(char c) {
  if (c == '^')
    return 3;
  else if (c == '/' || c == '*')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}

string infixToPostfix(string s) {
    stack<char> st;
    string res;
    int sz = s.size();

    for (int i = 0; i < sz; i++) {
        if (isalnum(s[i])) {
            res += s[i];
        } else if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && prec(s[i]) <= 
            prec(st.top())) {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    return res;
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.size(); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    string postfix = infixToPostfix (infix);
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

string postfixToInfix(string s) {
    int n = s.size();
    int i = 0;
    stack<string> st;
    while(i < n) {
        if(isalnum(s[i])) st.push(to_string(s[i]));
        else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string conStr = "(" + t2 + s[i] + t1 + ")";
            st.push(conStr);
        }
        i++;
    }
    return st.top();
}

string prefixToInfix(string s) {
    int n = s.size();
    int i = n - 1;
    stack<string> st;
    while(i >= 0) {
        if(isalnum(s[i])) st.push(to_string(s[i]));
        else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string conStr = "(" + t1 + s[i] + t2 + ")";
            st.push(conStr);
        }
        i--;
    }
    return st.top();
}

string postfixToPrefix(string s) {
    int n = s.size();
    int i = 0;
    stack<string> st;
    while(i < n) {
        if(isalnum(s[i])) st.push(to_string(s[i]));
        else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string conStr = s[i] + t2 + t1;
            st.push(conStr);
        }
        i++;
    }
    return st.top();
}

string prefixToPostfix(string s) {
    int n = s.size();
    int i = n - 1;
    stack<string> st;
    while(i >= 0) {
        if(isalnum(s[i])) st.push(to_string(s[i]));
        else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string conStr = t1 + t2 + s[i];
            st.push(conStr);
        }
        i--;
    }
    return st.top();
}

int main() {
  string exp = "(p+q)*(m-n)";
  cout << "Infix expression: " << exp << endl;
//   infixToPostfix(exp);
  cout << infixToPrefix("(a-b/c)*(a/k-l)");
  return 0;
}