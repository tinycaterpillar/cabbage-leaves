#include <bits/stdc++.h>
#define endl '\n' // don't use when you cover interactive problem
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int N, Q;
vector<vector<int> > edge, seg;
vector<int> perm, tin, tout;
int timer;

void dfs(int node, int prev = 0)
{
    tin[node] = ++timer;

    for(int nxt: edge[node]){
        if(nxt == prev) continue;
        dfs(nxt, node);
    }

    tout[node] = ++timer;
}

void init(int node, int sl, int sr)
{
    if(sl == sr){
        seg[node].emplace_back(tin[perm[sl]]);
    }
    else{
        int mid = (sl+sr)/2;
        init(2*node, sl, mid);
        init(2*node+1, mid+1, sr);
        merge(all(seg[2*node]), all(seg[2*node+1]), back_inserter(seg[node]));
    }
}

int query(int node, int sl, int sr, int l, int r, int lb, int ub)
{
    if(l <= sl && sr <= r){
        auto rp = upper_bound(all(seg[node]), ub+1);
        auto lp = lower_bound(all(seg[node]), lb);
        return rp-lp;
    }
    else if(r < sl || sr < l) return 0;
    else{
        int mid = (sl+sr)/2;
        return query(2*node, sl, mid, l, r, lb, ub) + query(2*node+1, mid+1, sr, l, r, lb, ub);
    }
}

void solve()
{
    cin >> N >> Q;
    edge.assign(N+1, vector<int>{});
    for(int i = 0; i < N-1; ++i){
        int u, v; cin >> u >> v;
        edge[u].emplace_back(v);
        edge[v].emplace_back(u);
    }

    perm.assign(N+1, 0);
    for(int i = 1; i <= N; ++i) cin >> perm[i];

    timer = 0;
    tin.assign(N+1, 0);
    tout.assign(N+1, 0);
    dfs(1);
    
    int h = ceil(log2(N));
    int seg_sz = (1 << (h+1));
    seg.assign(seg_sz, vector<int>{});

    init(1, 1, N);

    while(Q--){
        int l, r, x; cin >> l >> r >> x;
        cout << ((query(1, 1, N, l, r, tin[x], tout[x]) > 0)? "YES": "NO") << endl;
    }
    cout << endl;

}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int T; cin >> T;
    while(T--){
        solve();
    }

    return 0;
}