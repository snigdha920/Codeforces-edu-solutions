#include <bits/stdc++.h> 
using namespace std;

int main() {
    long double l = 1, r = 1e18, c;
    cin >> c;
    long double mid;
    for(int i=0; i<1000; i++) {
        mid = (l+r)/2;
        if(mid*mid + sqrt(mid) == c) {
            break;
        }
        else if(mid*mid + sqrt(mid) > c) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    cout << setprecision(16) << mid << "\n";
}
