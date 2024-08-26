#include<iostream> 
#include<vector>
#include<string>
#include<algorithm>
#include<cmath> 
#include<stack>
#include<queue>
using namespace std;
typedef pair<int, int>P;
typedef long long ll;
int n, m, cnt = 0, SN = 0;
vector<int>dfsn;
stack<int>s;
vector<bool>finished;
vector<vector<int>>adj;
vector<vector<int>>SCC;
vector<int>sn;
vector<int>resultcount;
int DFS(int cur) {
   dfsn[cur] = ++cnt;
   s.push(cur);
   int result = dfsn[cur];
   for (int next : adj[cur]) {
      if (dfsn[next]==0)result = min(result, DFS(next));
      else if (!finished[next])result = min(result, dfsn[next]);
   }
   if (result == cur) {
      vector<int>curscc;
      while (1) {
         int t = s.top();
         s.pop();
         curscc.push_back(t);
         finished[t] = true;
         sn[t] = SN;
         if (t == cur)break;
      }
      SCC.push_back(curscc);
      SN++;
   }
   return result;
}
int main() {
   cin.tie(0);
   cout.tie(0);
   ios::sync_with_stdio(false);
   while (1) {
      cin >> n;
      sn.resize(n + 1);
      adj.resize(n + 1);
      finished.resize(n + 1);
      dfsn.resize(n + 1);
      if (n == 0)return 0;
      cin >> m;

      for (int i = 0; i < m; i++) {
         int a, b;
         cin >> a >> b;
         adj[a].push_back(b);
      }
      for (int i = 1; i <= n; i++) {
         if (dfsn[i] == 0)DFS(i);
      }
      for (auto &k : SCC) {//sn안의 원소들
         bool check = true;
         for (int j : k) {
            for (int a : adj[j]) {
               if (sn[a] != sn[j]) {
                  check = false;
                  break;
               }
            }
            if (!check)break;
         }
         if (check) {
            for (int i = 0; i < k.size(); i++) {
               resultcount.push_back(k.at(i));
            }
         }
      }
      sort(resultcount.begin(), resultcount.end());
      for (int i = 0; i < resultcount.size(); i++) {
         cout << resultcount[i] << " ";
      }
      cout << "\n";
      sn.clear();
      finished.clear();
      adj.clear();
      dfsn.clear();
      SCC.clear();
      resultcount.clear();
      cnt = 0;
      SN = 0;
     }
   }