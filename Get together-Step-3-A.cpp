#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int n;
vector<double> x, v;

bool good(double time) {
    double maxf = INT_MIN, mine = INT_MAX;
    for(int i=0; i<n; i++) {
        double left = x[i] - v[i]*time;
        double right = x[i] + v[i]*time;
        // cout << "( " << left << ", " << right << " )" << endl;
        maxf = max(maxf, left);
        mine = min(mine, right);
    }
    return mine-maxf >= 0;
}

int main() {
    cin >> n;
    x.resize(n); v.resize(n);
    for(int i=0; i<n; i++) {
        cin >> x[i] >> v[i];
    }
    double l = 0, r = 2 * 1e9;
    int count = 0;
    for(int i=0; i<100; i++) {
        double mid = (l+r)/2;
        if(good(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    // cout << "number of steps are: " << count << endl;
    cout << setprecision(15) << r << "\n";
    return 0;
}
