#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli n, k;

bool good(lli x) {
    lli c = 0;
    for ( int i = 1; i <= n; i++ ) {
        if(x%i == 0) c += min (x/i - 1, n);
        else c += min(x/i, n);
    }
    return c < k;
}

int main() {
    cin >> n >> k;
    lli l = 1, r = n * n + 10;
    for(int i=0; i<80; i++) {
        lli mid = (l + r)/2;
        if( good (mid) ) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
    return 0;
}
