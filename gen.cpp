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

    vector<char> total;
    for(int i = 0; i < 26; ++i){
        total.emplace_back('A'+i);
    }
    
    cout << N << endl;
    for(int i = 1; i <= N; ++i){
        vector<char> cur;
        sample(total.begin(), total.end(), back_inserter(cur), 2, mt19937 {random_device{}()});

        cout << cur[0] << ' ' << cur[1] << ' ' << rnd.next(1, 10) << endl;
    }
}

// Tests
// <#list 1..5 as i>
//     gen ${i} > $
// </#list>