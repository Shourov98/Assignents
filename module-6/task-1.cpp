#include <iostream>
using namespace std;

bool checkPalindrom(string &s, int n, int i) {
    if(i == n) return true;
    
    if(s[n-1-i] != s[i]) return false;
    
    return checkPalindrom(s, n, i + 1);
}

int main()
{
    string s;
    cin >> s;
    
    int n = s.size();
    
    if(checkPalindrom(s, n, 0)) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}

// Time complexity  O(n)
// Space complexity  O(n)
