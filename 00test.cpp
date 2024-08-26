#include <bits/stdc++.h>
#define endl '\n' // don't use when you cover interactive problem
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

// return maximum flow with Edmonds-Karp
// use indices 0 to sz+2
struct Maximum_flow
{
    struct Edge
    {
        int from, to;
        int c, f; // capacity and flow
        Edge* rev;

        Edge(int from, int to, int c)
        : from{from}, to{to}, c{c}, f{0}, rev{nullptr} {}

        int r() { return c-f; }
        void add_flow(int f)
        {
            this->f += f;
            rev->f -= f;
        }
    };

    int MAX, S, T, INF; // upper_bound of available indices, source, sink and maximum possible flow in network.
    vector<vector<Edge*> > adj;
    Maximum_flow(int sz, int S, int T, int inf_flow)
    : MAX{sz+3}, S{S}, T{T}, INF{inf_flow} { adj.assign(MAX+1, vector<Edge*>{}); }

    // insert edge uv
    // In undirected graph, use rev_cap=0.
    void add_edge(int u, int v, int c, int rev_cap)
    {
        Edge *uv = new Edge(u, v, c), *vu = new Edge(v, u, rev_cap);
        uv->rev = vu;
        vu->rev = uv;
        adj[u].emplace_back(uv);
        adj[v].emplace_back(vu);
    }

    void make_maximum_flow()
    {
        while(true){
            // find augument path in residual network
            int cur_flow = 0;
            vector<bool> visited(MAX+1, false);
            vector<Edge*> path(MAX+1, nullptr);

            queue<pi> q;
            q.push(pi{S, INF});
            visited[S] = true;
            while(!q.empty() && visited[T]==false){
                auto [cur, cur_r] = q.front(); q.pop();
                for(Edge* e: adj[cur]){
                    if(visited[e->to] || e->r() == 0) continue;

                    q.push(pi{e->to, min(cur_r, e->r())});
                    visited[e->to] = true;
                    path[e->to] = e;
                    if(e->to == T) {
                        cur_flow = q.back().second;
                        break;
                    }
                }
            }

            if(cur_flow == 0) break;
            else{
                for(Edge* e=path[T]; e!=nullptr; e=path[e->from]){
                    e->add_flow(cur_flow);
                }
            }
        }
    }

    int get_maximum_flow()
    {
        make_maximum_flow();

        int ret = 0;
        for(Edge* e: adj[S]) ret += e->f;
        return ret;
    }
};

// use indices 0 to sz+2
struct Dsu
{
    int MAX; // size, upper_bound of available indices
    vector<int> parent;
    // -parent[A] := the number of reachable vertices from vertex A. Note that there is -.
    Dsu(int sz) : MAX{sz+3} { parent.assign(MAX, -1); }
    int Find(int u)
    {
        if(parent[u] < 0) return u;
        return parent[u] = Find(parent[u]);
    }

    // return whether union u and v is occured of not. If ture, there is an union of them.
    bool Union(int u, int v)
    {
        int pu = Find(u);
        int pv = Find(v);

        if(pu == pv) return false;
        // pu set is bigger than pv set
        else if(parent[pu] < parent[pv]){
            parent[pu] += parent[pv];
            parent[pv] = pu;
            return true;
        }
        else{
            parent[pv] += parent[pu];
            parent[pu] = pv;
            return true;
        }
    }
};

const int INF = 1e9;
int M, N, S, T;
vector<int> pig;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    cin >> M >> N;
    pig.assign(M+1, 0);
    for(int p = 1; p <= M; ++p) cin >> pig[p];

    S = 0, T = N+M+1;
    Maximum_flow mx{N+M+2, S, T, INF};
    for(int p = 1; p <= M; ++p){
        mx.add_edge(S, p, pig[p], 0);
    }

    Dsu dsu{M};
    for(int man = 1; man <= N; ++man){
        int cnt; cin >> cnt;
        vector<int> key(cnt);
        for(auto& k: key) {
            cin >> k;
            mx.add_edge(k, man+M, INF, 0);
        }
        int want; cin >> want;
        mx.add_edge(man+M, T, want, 0);

        for(int i = 1; i < cnt; ++i){
            if(dsu.Union(key[0], key[i])){
                mx.add_edge(key[0], key[i], INF, INF);
            }
        }
        cout << mx.get_maximum_flow() << endl;
    }
    cout << mx.get_maximum_flow() << endl;

    return 0;
}