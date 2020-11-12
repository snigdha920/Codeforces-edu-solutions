#include <bits/stdc++.h>
using namespace std;

int n, x, y;

bool good(long long int t) {
    long long int time = t - min(x, y);
    if(time < 0) return false;
    return (floor(time/x) + floor(time/y)) >= n-1;
}

int main() {
    cin >> n >> x >> y;
    long long int l = 0, r = 2*1e9;
    while(l + 1 < r) {
        long long int mid = (l + r)/2;
        if(good(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << "\n";
}
