#include <bits/stdc++.h>
#define endl '\n' // don't use when you cover interactive problem
#define all(v) v.begin(), v.end()
#define INF 1001
#define MAX 52
#define NON -1

using namespace std;

int N;
int cap[MAX][MAX];
int flo[MAX][MAX];
int parent[MAX];
vector<int> edge[MAX];

int conv(char c)
{
    if('A' <= c && c <= 'Z') return c - 'A';
    else return 26 + (c-'a');
}

int s = conv('A'), t = conv('Z');

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        char u, v; cin >> u >> v;
        int c; cin >> c;
        int cu = conv(u);
        int cv = conv(v);
        cap[cu][cv] = cap[cv][cu] += c;        
        edge[cu].emplace_back(cv);
        edge[cv].emplace_back(cu);
    }

    int total = 0;
    while(1){
        fill_n(parent, MAX, NON);

        queue<int> q;
        q.push(s);
        parent[s] = s;
        while(!q.empty() && parent[t] == NON){
            auto cur = q.front(); q.pop();

            for(int nxt: edge[cur]){
                if(parent[nxt] != NON) continue;
                if(cap[cur][nxt] - flo[cur][nxt] <= 0) continue;

                q.push(nxt);
                parent[nxt] = cur;
                if(nxt == t) break;
            }
        }

        if(parent[t] == NON) break;

        int f = INF;
        for(int i = t; i != s; i=parent[i]){
            f = min(f, cap[parent[i]][i] - flo[parent[i]][i]);
        }

        for(int i = t; i != s; i=parent[i]){
            flo[parent[i]][i] += f;
            flo[i][parent[i]] -= f;
        }
        total += f;
    }
    cout << total << endl;

    return 0;
}