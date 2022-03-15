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
    while(n--){
        string s1, s2; cin >> s1 >> s2;

        if(s1.size() != s2.size()){
            cout << "Impossible" << endl;
            continue;
        }

        vector<int> cnt_s1(26), cnt_s2(26);
        ooop(i, s1.size()){
            cnt_s1[s1[i]-'a']++;
            cnt_s2[s2[i]-'a']++;
        }

        bool flag = true;
        ooop(i, 26){
            if(cnt_s1[i] != cnt_s2[i]) {
                flag = false;
                break;
            }
        }
        cout << (flag? "Possible": "Impossible") << endl;
    }

    return 0;
}