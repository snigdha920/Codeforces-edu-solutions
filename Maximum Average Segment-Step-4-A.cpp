#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int n, d;
vector<int> a;
int leftAns, rightAns;

bool good(double x) {
    double p[n];
    vector<pair<double, double>>mini(n);
    mini[0].first = a[0]-x; mini[0].second = 0;
    p[0] = a[0]-x;
    bool flag = 0;
    double cur_sum = p[0];
    for(int i=1; i<n; i++) {
        cur_sum += (a[i]-x);
        p[i] = cur_sum;
        if(p[i] <= mini[i-1].first) {
            mini[i].first = cur_sum;
            mini[i].second = i;
        } else {
            mini[i].first = mini[i-1].first;
            mini[i].second = mini[i-1].second;
        }
    }
    for(int i=n-1; i+1-d >= 0; i--) {
        if(i+1-d >= 0 && p[i]>=0) {
            leftAns = 0;
            rightAns = i;
            flag = 1;
            break;
        }
        if(mini[i-d].first <= p[i]) {
//            cout << p[i] << " - " << mini[i-d].second << endl;
            leftAns = mini[i-d].second+1;
            rightAns = i;
            flag = 1;
            break;
        }
    }
    return flag;
}
int main() {
    cin >> n >> d;
    a.resize(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    double l = 0, r = 110;
    for(int i=0; i<110; i++) {
        double mid = (l+r)/2;
        if(good(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
//    good(l);
//    cout << l << endl;
//    cout << good(6.66) << endl;
    cout << leftAns+1 << " " << rightAns+1 << endl;
}
