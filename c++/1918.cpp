#include <bits/stdc++.h>
#define endl "\n" // don't use when you cover interactive problem
#define ooop(i, n) for(int i = 0; i < n; i++)
#define loop(i, n) for(int i = 1; i <= n; i++)
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

string s;

struct chunk
{
    string s;
};

chunk f(int head, int tail)
{
    int tmp = -1;
    for(int i = head; i < tail; i++){
        if(s[i] == '('){
            tmp = i;

        }
        else{

        }
    }


}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> s;
    cout << f(0, s.size()).s << endl;

    return 0;
}