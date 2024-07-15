#include <iostream>
using namespace std;

int rec_multiply(int mx,int mn,int mul) {
    if(mn == 0) return mul;
    mul += mx;
    return rec_multiply(mx, mn-1, mul);
}

int main() {
    int a, b;
    cin >> a >> b;
    int mul = 0;
    int mx = max(a, b);
    int mn = min(a, b);
    cout << rec_multiply(mx, mn, mul);
    
    return 0;
}

// Time complexity  O(n)
// Space complexity  O(n)
