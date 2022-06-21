#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long dp[3030][2525];//dp[i][j] = i번 도시에서 z로 나눈 나머지가 j일때까지 걸리는 최소 시간
vector<pair<int,int>> v[3030];

vector<long long> solution(int n, int z, vector<vector<int>> roads, vector<long long> queries) {
    vector<long long> answer;

    for(int i = 0 ; i < 3030; i++){
        for(int j = 0 ; j < 2525; j++){
            dp[i][j] = 1e18;
        }
    }

    for(int i = 0; i < roads.size(); i++){
        v[roads[i][0]].push_back({roads[i][1], roads[i][2]});
    }
    for(int i = 0; i < n ; i ++){
        dp[i][0] = 1;
    }

    dp[0][0] = 0;

    // for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++){
            for(pair<int,int> next : v[j]){
                for(int k = 0; k < z; k++){
                    if(k + next.second >= z*z)continue;
                    dp[next.first][k+next.second] = min(dp[next.first][k+next.second], dp[j][k] + 1);
                    for(int nn = 0; nn < n; nn++){
                        dp[next.first][k+next.second] = min(dp[next.first][k+next.second], dp[nn][k] + 2);
                    }
                }
            }
        }
    // }

    for(int i = 0; i < queries.size(); i++){
        long long q = queries[i];
        long long ans = q/z;
        q %= z;
        if(q){
            long long mn = 1e18;
            int kk = 0;
            for(int j = 0; j < n; j++){
                for(int k = 0; k < z; k++){
                    if(q+k*z >= z*z)continue;
                    if(mn > dp[j][q+k*z]){
                        mn = dp[j][q+k*z];
                        kk = k;
                    }
                }
            }
            if(mn == 1e18) ans = -1;
            else{
                if(ans < kk)ans = -1;
                else ans = ans - kk + mn;
            }
        }
        answer.push_back(ans);
    }

    return answer;
}