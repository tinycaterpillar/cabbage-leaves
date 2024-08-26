#include "testlib.h"
#include <iostream>
#include <utility>
#include <random>

using namespace std;
typedef pair<int, int> pi;
 
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
 
    /* Single random number between 1 and 1000000 inclusive. */
    // int N = rnd.next(1, 5000);
    // int M = rnd.next(0, 100000);
    int N = rnd.next(1, 10);
    int mub = 20;
    int M = rnd.next(0, min(N*(N-1)/2, mub));
    int S = rnd.next(1, N);
    int T = rnd.next(1, N);

    vector<pi> total;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            if(i == j) continue;
            total.push_back(pi{i, j});
        }        
    }

    vector<pi> edge;
    sample(total.begin(), total.end(), back_inserter(edge), M, mt19937 {random_device{}()});
    
    cout << N << ' ' << M << endl;
    for(auto& [i, j]: edge){
        cout << i << ' ' << j << endl;
    }
}

// Tests
// <#list 1..5 as i>
//     gen ${i} > $
// </#list>