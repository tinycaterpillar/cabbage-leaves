#include <bits/stdc++.h>
#define endl "\n" // don't use when you cover interactive problem
#define ooop(i, n) for(int i = 0; i < n; i++)
#define loop(i, n) for(int i = 1; i <= n; i++)
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n; cin >> n;
    vector<int> v(n);
    for(auto& e: v) cin >> e;
    int tar; cin >> tar;
    int cnt = 0;
    for(const auto& e: v){
        if(tar == e) cnt++;
    }
    cout << cnt << endl;

    return 0;
}