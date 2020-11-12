#include <limits>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;
  
#define fo(i, n) for (int i = 0; i < n; i++)
#define sc(x) cin >> x
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define pr(x) cout << x << endl
#define prs(x) cout << x << " "
#define pse(x) cout << x << " " << endl;
#define br cout << endl
#define len(x) x.size()
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<lli, lli> plli;
typedef vector<int> vi;
typedef vector<lli> vlli;
typedef vector<pii> vpii;
typedef vector<plli> vplli;
const lli INF = 1000000000;
lli max(lli a, lli b){ return (a>b)?a:b; }
lli min(lli a, lli b){ return (a<b)?a:b; }
lli ssum(lli n) {return (n * (n + 1)) / 2;}
lli gcd(lli a, lli b) {if (b == 0)return a; return gcd(b, a % b);}
lli lcm(lli a,lli b){return (a*b)/(gcd(a,b));}

lli w = 1, h = 1, n = 1;

bool good(lli x) {
    return (x / w) * (x / h) >= n;
}

// Driver Code
int main()
{
    // Fast Input/Output
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // Input output
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    #endif
  
    // Test Cases
    int t = 1;
    // cin >> t;
  
    while (t--)
    {
        //binary search
        //invariant
        /*
        a[l] < minimum good number
        a[r] >= minimum good number
        x is good -> x+1 is good
        */
        cin >> w >> h >> n;
        lli l = 0, r = 1;
        while(!good(r)) r*=2;
        while(l+1 < r)
        {
            lli mid = (l+r)/2;
            if(good(mid) == false) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << r << "\n";
    }
    return 0;
}
