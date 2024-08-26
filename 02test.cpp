#include <bits/stdc++.h>
#define endl '\n' // don't use when you cover interactive problem
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    string s; cin >> s;
    if(s == "-1") cout << s << endl;
    else{
        int a = 0, b = 0;
        int ans = 0;
        for(auto c: s){
            if(c == 'A'){
                a += 1;
            }
            else if(c == 'B'){
                b += 1;
                ans += a;
            }
            else{
                ans += a+b;
            }
        }
        cout << ans << endl;
    }

    return 0;
}