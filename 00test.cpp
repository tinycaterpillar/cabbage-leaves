#include <bits/stdc++.h>
#define endl '\n' // don't use when you cover interactive problem
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int N, M;
string S, A, B;
vector<vector<int> > v;
vector<pi> w;
vector<vector<bool> > fail;

bool go(int dep, int tar, int ind)
{
    if(dep == N) return true;
    if(fail[dep][tar]) return false;

    bool ret = false;



}

void solve()
{
    cin >> S;
    N = S.size();
    v.assign(10, vector<int>{});
    for(int i = 0; i < N; ++i){
        v[S[i]-'0'].emplace_back(i);
    }

    cin >> M >> A >> B;
    for(int i = 0; i < M; ++i){
        w.emplace_back(pi{A[i]-'0', B[i]-'0'});
    }

    fail.assign(M, vector<bool>(10, false));
    for(int i = w[0].first; i <= w[0].second; ++i){
        if(go(0, i, 0)){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int T; cin >> T;
    while(T--){
        solve();
    }

    return 0;
}