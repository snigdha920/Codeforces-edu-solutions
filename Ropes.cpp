#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int n, k;

bool good(double x) {
    double s = 0;
    for(int i=0; i<n; i++) {
        s += floor(a[i]/x);
    }
    return (s >= k);
}

int main() {
    cin >> n >> k;
    a.resize(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    double l = 0, r = 1e8;
    // l is good, r is bad
    for(int i=0; i<100; i++) {
        double mid = (l + r) / 2;
        if(good(mid) == true) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << setprecision(8) << l << "\n";
    return 0;
}
