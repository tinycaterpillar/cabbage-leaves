#include <bits/stdc++.h>
#include <format>
#define endl '\n' // don't use when you cover interactive problem

using namespace std;

int A, B, C; // A <= B <= C
set<string> visited;

void sort_abc()
{
    if(A > B) swap(A, B);
    if(A > C) swap(A, C);
    if(B > C) swap(B, C);
}

void set_back(int tmp_a, int tmp_b, int tmp_c){
    A = tmp_a;
    B = tmp_b;
    C = tmp_c;
}

string encode()
{
    stringstream ss;
    ss << format("{:0>3}", A);
    ss << format("{:0>3}", B);
    ss << format("{:0>3}", C);
    return ss.str();
}

bool dfs()
{
    visited.insert(encode());

    if(A < C){
        int tmp_a = A, tmp_b = B, tmp_c = C;
        
        if(A < B){
            B -= A;
            A *= 2;
            sort_abc();
            if(visited.find(encode()) != visited.end() && dfs()) return true;
            set_back(tmp_a, tmp_b, tmp_c);
        }

        if(B < C){
            C -= B;
            B *= 2;
            sort_abc();
            if(visited.find(encode()) != visited.end() && dfs()) return true;
            set_back(tmp_a, tmp_b, tmp_c);
        }

        C -= A;
        A *= 2;
        sort_abc();
        if(visited.find(encode()) != visited.end() && dfs()) return true;
        set_back(tmp_a, tmp_b, tmp_c);

        return false;
    }
    else return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> A >> B >> C;
    sort_abc();
    cout << dfs() << endl;
    for(auto e: visited) cout << e << endl;

    return 0;
}