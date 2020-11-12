#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

vector<pair<lli, lli>>p;
int n, k;

bool good(lli x) {
    lli c = 0;
    for(int i = 0; i < p.size(); i++) {
        if(p[i].first > x) c += 0;
        else if (p[i].second < x) c += (p[i].second - p[i].first + 1);
        else c += x - p[i].first;
    }
    return c <= k;
}

int main() {
    cin >> n >> k;
    p.resize(n);
    lli l = INT_MAX, r = INT_MIN;
    for (int i=0; i<n; i++) {
        cin >> p[i].first >> p[i].second;
        l = l > p[i].first ? p[i].first : l;
        r = r > p[i].second ? r : p[i].second;
    }
    l = INT_MIN; r = INT_MAX;
    for(int i=0; i<60; i++) {
        lli mid = (l + r)/2;
        // if(i%25 == 0) cout << "mid is: " << mid << endl;
        // mid is good if calc(mid) <= k
        if( good (mid) ) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
    return 0;
}
