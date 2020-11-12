#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int k, n;
vector<lli>a;

bool good(long long int councils) {
    long long int sum = 0;
    for(int i=0; i<n; i++) {
        if (a[i] > councils) sum += councils;
        else sum += a[i];
    }
    return (sum/councils) >= k;
}

int main () {
    
    cin >> k >> n;
    a.resize(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    long long int l = 0, r = 25 * 1e9 + 10;
    while(l+1 < r) {
        long long int mid = (l+r)/2;
        if(good(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << "\n";
    return 0;
}
