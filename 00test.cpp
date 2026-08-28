#include <bits/stdc++.h>
#define endl '\n' // don't use when you cover interactive problem
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int N, M;
vector<vector<int> > edge;
vector<int> visited;

bool dfs(int cur, int dep)
{
    visited[cur] = (dep&1);

    for(auto& nxt: edge[cur]){
        if(visited[nxt] == -1) return dfs(nxt, dep+1);
        if(visited[nxt] == (dep&1)) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    cin >> N >> M;
    edge.assign(N+1, vector<int>());
    visited.assign(N+1, -1);
    for(int i = 0; i < M; ++i){
        int u, v; cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    bool flag = true;
    for(int i = 1; i <= N; ++i){
        if(!flag || visited[i] != -1) continue;
        if(!dfs(i, 0)) flag = false;
    }

    for(auto& e: visited) cout << e << ' ';
    cout << endl;

    if(flag){
        for(int i = 1; i <= N; ++i){
            cout << visited[i] + 1 << ' ';
            cout << endl;
        }
    }
    else cout << "IMPOSSIBLE" << endl;

    return 0;
}