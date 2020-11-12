#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int n, k;
vector <lli> a, b;

bool calc( lli x ) {
    lli cnt = 0;
    int i = 0, j = 0;
    while( i < n && j < n) {
        if( a[i] + b[j] >= x) {
            j++;
        } else {
            i++;
            cnt += (n-j);
        }
    }
    return cnt < k;
}

int main() {
    cin >> n >> k;
    a.resize(n);
    b.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<lli>());
    lli l = 1, r = 2e9 + 10;
    for (int i = 0; i < 80; i++) {
        lli mid = (l + r)/2;
        if( calc(mid) ) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
    // cout << calc(9);
    return 0;
}
