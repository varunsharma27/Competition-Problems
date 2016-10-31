/*
 * Problem Statement : https://www.hackerrank.com/challenges/apple-and-orange
 *
 */


#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int s;
    int t;
    cin >> s >> t;
    int a;
    int b;
    cin >> a >> b;
    int m;
    int n;
    cin >> m >> n;
    vector<int> apple(m), a_dist(m);
    int a_result = 0;
    for(int apple_i = 0;apple_i < m;apple_i++){
       cin >> apple[apple_i];
        a_dist[apple_i] = a + apple[apple_i];
        if (a_dist[apple_i] <= t && a_dist[apple_i] >= s)
            a_result++;
    }
    vector<int> orange(n), o_dist(n);
    int o_result = 0;
    for(int orange_i = 0;orange_i < n;orange_i++){
       cin >> orange[orange_i];
       o_dist[orange_i] = b + orange[orange_i];
       if (o_dist[orange_i] <= t && o_dist[orange_i] >= s)
           o_result++;
    }
    cout<<a_result<<endl<<o_result;
    
    return 0;
}
