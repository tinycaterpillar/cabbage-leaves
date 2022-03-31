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

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> d(n);
        for(auto& e: d) cin >> e;

        vector<int> sorted(all(d));
        sort(all(sorted));
        map<int, pi> cnt; // {odd, even}
        ooop(i, n){
            if(i%2 == 0) cnt[d[i]].second++;
            else cnt[d[i]].first++;
        }

        bool avail = true;
        for(const auto& [tar, pair]: cnt){
            int cri = pair.first - pair.second;
            if(abs(cri) > 1){
                avail = false;
                break;
            }

            if(cri == 0) continue;

            int ind = (lower_bound(all(sorted), tar) - sorted.begin())%2;
            if(ind == 1 && cri == -1 || ind == 0 && cri == 1){
                avail = false;
                break;
            }
        }
        cout << ((avail)? "YES": "NO") << endl;
    }

    return 0;
}