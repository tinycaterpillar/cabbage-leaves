#include <bits/stdc++.h>
#define endl "\n" // don't use when you cover interactive problem
#define ooop(i, n) for(int i = 0; i < n; i++)
#define loop(i, n) for(int i = 1; i <= n; i++)
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

ll ceil(ll a, ll b)
{
    return (a-1)/b + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    ll n, C; cin >> n >> C;
    vector<ll> squad(n);
    vector<ll> c(n);
    ooop(i, n){
        cin >> c[i];
        ll d, h; cin >> d >> h;
        squad[i] = d*h;
    }

    ll m; cin >> m;
    vector<ll> monster(m);
    ooop(i, m){
        ll d, h; cin >> d >> h;
        monster[i] = d*h;
    }

    ooop(i, m){
        ll minval = C+1;
        ooop(j, n) minval = min(minval, c[j]*ceil(monster[i]+1, squad[j]));
        cout << ((minval == C+1)? -1: minval) << ' ';
    }
    cout << endl;

    return 0;
}