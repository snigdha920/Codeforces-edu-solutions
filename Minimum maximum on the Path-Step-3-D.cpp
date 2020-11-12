#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

vector<vector<pair<lli, lli>>> adj;
int n, m, d;
bool good(lli limit) {
    bool visited[n+1];
    memset(visited, 0, sizeof(visited));
    queue<lli> q;
    lli level = 0, sz = 1;
    bool flag = 0;
    q.push(1);
    while(!q.empty()) {
        sz--;
        lli v = q.front(); q.pop();
        // cout << "v is: " << v << endl;
        if(v == n) {
            flag = 1;
            break;
        }
        // cout << "here" << endl;
        for(lli i = 0 ; i < adj[v].size(); i++) {
            // cout << "vtx: " << adj[v][i].first << ", wt: " << adj[v][i].second << endl;
            if(visited[adj[v][i].first] != 1 && adj[v][i].second <= limit) {
                // cout << "visiting: " << adj[v][i].first << endl;
                q.push(adj[v][i].first);
                visited[adj[v][i].first] = 1;
            }
        }
        if(sz == 0) {
            sz = q.size();
            // cout << "sz: " << sz << endl;
            level++;
        }
    }
    // cout << "level: " << level << endl;
    if(flag == 0) return 0;
    else return level <= d;
}
vector<lli> result;
bool visitedUtil[100010];
bool dfs(lli vtx, lli level, lli limit) {
    if(level > d) return false;
    if(vtx == n) {
        return true;
    }
    // cout << "vtx: " << vtx << endl;
    for(int i = 0; i < adj[vtx].size(); i++) {
        if(visitedUtil[adj[vtx][i].first] != 1 && adj[vtx][i].second <= limit) {
            if(adj[vtx][i].first != n) visitedUtil[adj[vtx][i].first] = 1;
            if( dfs(adj[vtx][i].first, level+1, limit) == true ) {
                // cout << "vtx is: " << vtx << endl;
                result.push_back(adj[vtx][i].first);    
                return true;
            } else if(vtx == 1) {
                result.clear();
                memset(visitedUtil, 0, sizeof(visitedUtil));
            }
        } 
    }
    return false;
}
int main() {
    cin >> n >> m >> d;
    adj.resize(n+1, vector<pair<lli, lli>>());
    for(int i=0; i<m; i++) {
        lli v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        adj[v1].push_back({v2, wt});
    }
    lli l = 0, r = 1e9 + 100;
    while(l+1 < r) {
        lli mid = (l+r)/2;
        if(good(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    // cout << r << endl;
    if(r == 1e9 + 100) {
        cout << "-1";
    } else {
        memset(visitedUtil, 0, sizeof(visitedUtil));
        dfs(1, 0, r);
        cout << result.size() << endl;
        cout << 1 << " ";
        for(int i=result.size()-1; i >= 0; i--) {
            cout << result[i] << " ";
        }
    }
}
