#include <bits/stdc++.h>
using namespace std;

string removeAdjacentDuplicate(string s) {
    int n = s.size();
    stack<char>stk;
    for(int i = 0; i < n; i++) {
        if(stk.size() > 0) {
            char temp = stk.top();
            if(temp == s[i]){
                stk.pop();
            } else {
                stk.push(s[i]);
            }
        } else {
            stk.push(s[i]);
        }
    }

    if(stk.empty()){
        return "-1";
    }
    string ans = "";
    while(!stk.empty()) {
        char temp = stk.top();
        ans += temp;
        stk.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
     
int main() {
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        string ans = removeAdjacentDuplicate(s);
        cout << ans << endl;
    }

    return 0;
}
