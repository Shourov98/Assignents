#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char>stk;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            stk.push(s[i]);
        else{
            if(stk.empty())
                return false;
                
            if(s[i] == ')' && stk.top() == '(')
                    stk.pop();
            else if(s[i] == '}' && stk.top() == '{')
                stk.pop();
            else if(s[i] == ']' && stk.top() == '[')
                stk.pop();
            else
                return false;
        }
    }
    return stk.empty();
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;

        if(isValid(s)) {
            cout << "Valid" << endl;
        } else {
            cout << "Not valid" << endl;
        }
    }

    return 0;
}
