#include <bits/stdc++.h>
#define endl '\n' // don't use when you cover interactive problem
#define all(v) v.begin(), v.end()
#define NON -1
#define BRIDGE 100
#define SEQ 20

using namespace std;
typedef long long ll; 

ll sz, bz; // sequence size, bridge size
string seq;
string bridge[2];
ll dp[2][BRIDGE][SEQ]; // dp[flag][bridge][dep]

// flag := 악마다리(0)? 천사다리(1)?, ind := 다리 index, dep := 두루마리 index
ll go(ll flag, ll ind, ll dep)
{
    if(dp[flag][ind][dep] != NON) return dp[flag][ind][dep];
    
    if(ind == bz) return dep == sz;
    if(dep == sz) return 1;

    // 사용할 수 있음
    if(bridge[flag][ind] == seq[dep]){
        return dp[flag][ind][dep] = go(flag^1, ind+1, dep+1) + go(flag, ind+1, dep);
    }   
    // 사용할 수 없음
    else{
        return dp[flag][ind][dep] = go(flag, ind+1, dep);
    } 
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    cin >> seq >> bridge[0] >> bridge[1];
    sz = seq.size(), bz = bridge[0].size();
    assert(sz <= 20);
    assert(bz <= 100);

    for(ll i = 0; i < BRIDGE; i++){
        for(ll j = 0; j < SEQ; j++) dp[0][i][j] = dp[1][i][j] = NON;
    }

    cout << go(0, 0, 0) + go(1, 0, 0) << endl;

    return 0;
}