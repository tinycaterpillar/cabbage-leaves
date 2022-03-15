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

    vector<bool> check(30);
    ooop(i, 28){
        int tmp; cin >> tmp;
        check[tmp-1] = true;
    }

    ooop(i, 30){
        if(!check[i]) cout << i+1 << endl;
    }

    return 0;
}