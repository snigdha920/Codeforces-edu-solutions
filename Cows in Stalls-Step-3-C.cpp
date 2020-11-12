#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int n, k;
vector<lli> pos;
bool good(lli x) {
    bool flag = 1;
    int count = 1;
    for(int i=0; i<n; i++) {
        int j = i+1;
        while(j < n && pos[i]+x > pos[j]) j++;
        if(j == n) break;
        count++;
        i = j-1;
    }
    return count >= k;
}
int main () {
    cin >> n >> k;
    pos.resize(n);
    for(int i=0; i<n; i++) {
        cin >> pos[i];
    }
    int l = 0, r = pos[n-1]-pos[0]+10;
    while(l+1 < r) {
        lli mid = (l+r)/2;
        if(good(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
    return 0;
}
