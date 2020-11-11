#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

vector<pair<int, int>> p;
int n, k;

bool good(double x) {
    vector<double> m(n);
    for (int i = 0; i < n; i++) {
        m[i] = p[i].first - x*p[i].second;
    }
    sort(m.begin(), m.end());
    double sum = 0;
    for(int i=n-1; i>=n-k; i--) {
        sum += m[i];
    }
    return sum >= 0;
}

int main () {
    cin >> n >> k;
    p.resize(n);
    for (int i=0; i<n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    double l = 0, r = 100000;
    for(int i=0; i < 80; i++) {
        double mid = (l + r)/2;
        if(good(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << setprecision(10) << l << endl;
}