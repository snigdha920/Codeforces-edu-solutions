#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli max(lli a, lli b){ return a>b?a:b; }

string re;
lli nb, ns, nc, pb, ps, pc;
lli c[3];
lli r;

bool good(lli x) {
    lli br = c[0]*x, sr = c[1]*x, cr = c[2]*x;
    lli difb= max(br-nb, 0), difs= max(sr-ns, 0), difc=max(cr-nc, 0);
    if((difb*pb + difc*pc + difs*ps) > r) {
        return false;
    } else {
        return true;
    }
}

int main() {
    cin >> re;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;
    lli len = re.length();
    memset(c, 0, sizeof(c));
    for(int i=0; i<len; i++) {
        if(re[i] == 'B') c[0]++;
        else if(re[i] == 'S') c[1]++;
        else c[2]++;
    }
    lli left = 0, right = 1e13;
    while(left+1 < right) {
        lli mid = (left+right)/2;
        if(good(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    cout << left << "\n";
}
