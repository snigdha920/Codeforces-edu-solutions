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
        
        if(v == n) {
            flag = 1;
            break;
        }

        for(lli i = 0 ; i < adj[v].size(); i++) {
            
            if(visited[adj[v][i].first] != 1 && adj[v][i].second <= limit) {
                
                q.push(adj[v][i].first);
                visited[adj[v][i].first] = 1;
            }
        }

        if(sz == 0) {
            sz = q.size();
            level++;
        }
    }
    
    if(flag == 0) return 0;
    else return level <= d;
}

vector<lli> result;

bool visitedUtil[100010];

bool dfs(lli vtx, lli level, lli limit) {
    
    if(level > d) 
    return false;

    if(vtx == n) {
        return true;
    }
    
    for(int i = 0; i < adj[vtx].size(); i++) {
        
        if(visitedUtil[adj[vtx][i].first] != 1 && adj[vtx][i].second <= limit) {
            
            if(adj[vtx][i].first != n) visitedUtil[adj[vtx][i].first] = 1;
            
            if( dfs(adj[vtx][i].first, level+1, limit) == true ) {
                
                result.push_back(adj[vtx][i].first);
                return true;
            } 
            else if(vtx == 1) {
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
    lli ans=-1;
    while(l<=r) {
        lli mid = l + (r-l)/2;

        if(good(mid)) {
            ans=mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    
    if(ans==-1) {
        cout << "-1";
    } else {
        memset(visitedUtil, 0, sizeof(visitedUtil));
        dfs(1, 0, ans);
        cout << result.size() << endl;
        cout << 1 << " ";
        for(int i=result.size()-1; i >= 0; i--) {
            cout << result[i] << " ";
        }
    }

    return 0;
}