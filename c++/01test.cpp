#include <bits/stdc++.h>
#define endl "\n" // don't use when you cover interactive problem
#define ooop(i, n) for(int i = 0; i < n; i++)
#define loop(i, n) for(int i = 1; i <= n; i++)
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

char lower_alpha(char s)
{
    if('A' <= s && s <= 'Z') return (s - 'A')+(int)'a';
    else return s;
}

void print(string s, int p)
{
    ooop(j, p) cout << s[j];
    cout << '[' << s[p] << ']';
    for(int j = p+1; j < s.size(); j++) cout << s[j];
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n; cin >> n;

    bool check[26] {};
    while(n--){
        string s;
        getline(cin, s);
        bool issetting = false;

        cout << s << endl;
        int head_ascii = lower_alpha(s[0])-'a';
        if(!check[head_ascii]) {
            check[head_ascii] = true;
            print(s, 0);
            continue;
        }

        for(int i = 1; i < s.size(); i++){
            if(s[i] == ' '){
                int tar_ascii = lower_alpha(s[i+1])-'a';
                if(!check[tar_ascii]){
                    check[tar_ascii] = true;
                    print(s, i);
                    continue;
                }
            }
        }

        ooop(i, s.size()){
            int tar_ascii = lower_alpha(s[i])-'a';
            if(!check[tar_ascii]){
                check[tar_ascii] = true;
                print(s, i);
                continue;
            }
        }

        cout << s << endl;
    }

    return 0;
}