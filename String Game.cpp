#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

string t, p;
vector<long long int> a;

bool check(long long int x) {
    long long int i = 0, j = 0;
    string temp = "";
    unordered_set<long long int> set;
    for(long long int k=1; k<=x; k++) {
        set.insert(a[k]-1);
    }
    long long int lt = t.length();
    for(long long int i=0; i<lt; i++) {
        if(set.find(i) == set.end()) {
            temp += t[i];
        }
    }
    // cout << "temp is: " << temp << endl;
    long long int ltemp = temp.length(), lp = p.length();
    while( i < ltemp && j < lp ) {
        while(i < ltemp && temp[i] != p[j]) i++;
        if(temp[i] == p[j]) {
            i++; j++;
        }
    }
    return j == lp;
}
int main() {
    cin >> t;
    cin >> p;
    long long lt = t.length(), lp = p.length();
    a.resize(lt+1);
    for(long long int i=1; i<=lt; i++) {
        cin >> a[i];
    }
    //Corner cases 
    if(lp == 0) {
        cout << lt << endl;
        return 0;
    }
    long long int l = 0, r = lt-lp + 1;
    while(l+1 < r) {
        long long int mid = (l+r)/2;
        if(check(mid) == true) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << l << "\n";
}
