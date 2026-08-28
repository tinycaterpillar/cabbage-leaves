#include <bits/stdc++.h>
#define endl '\n' // don't use when you cover interactive problem
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int N;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    
    cin >> N;
    vector<multiset<int>> adj(N);
    for(int u = 0; u < N; ++u){
        for(int v = 0; v < N; ++v){
            int cnt; cin >> cnt;
            while(cnt--){
                adj[u].insert(v);
            }
        }
    }

    for(auto lis: adj){
        if(lis.size()%2 > 0){
            cout << -1 << endl;
            return 0;
        }
    }

    vector<int> res;
    stack<int> st; st.push(0);

    // Hierholzer
    while (!st.empty()) {
        int v = st.top();

        if (!adj[v].empty()) {
            int u = *adj[v].begin();
            adj[v].erase(adj[v].begin());
            adj[u].erase(adj[u].find(v));
            st.push(u);
        } else {
            res.push_back(v);
            st.pop();
        }
    }

    for(auto u: res) cout << u+1 << ' ';
    cout << endl;

    return 0;
}