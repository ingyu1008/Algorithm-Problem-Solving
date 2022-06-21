#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long sum[303030];
vector<int> v[303030];
bool visited[303030];
long long ans = 0;

long long dfs(int node, vector<int> &a){
    long long sum = a[node];
    visited[node] = true;
    for(int next : v[node]){
        if(!visited[next]){
            sum += dfs(next, a);
        }
    }
    ans += abs(sum);
    return sum;
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = 0;
    long long sum = a[a.size() -1];
    
    for(int i = 0; i < a.size() -1; i++){
        sum += a[i];
        v[edges[i][0]].push_back(edges[i][1]);
        v[edges[i][1]].push_back(edges[i][0]);
    }
    
    if(sum != 0) return -1;
    else {
        dfs(0,a);
        return ans;
    }
}