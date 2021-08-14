#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, M;
    std::cin >> N >> M;
    std::vector<int> v[20101];
    std::vector<int> rv[20101];

    int A, B;
    for (int i = 0; i < M; i++)
    {
        std::cin >> A >> B;
        v[abs(A) + (A>0)*10000].push_back(abs(B) + (B<0)*10000);
        v[abs(B) + (B>0)*10000].push_back(abs(A) + (A<0)*10000);
        
        rv[abs(A) + (A<0)*10000].push_back(abs(B) + (B>0)*10000);
        rv[abs(B) + (B<0)*10000].push_back(abs(A) + (A>0)*10000);
    }

    std::stack<int> s;
    std::stack<int> st;

    for (int i = N; i >= 1; i--)
    {
        s.push(i);
        s.push(i+10000);
    }

    bool visited[20101];
    bool visited2[20101];
    std::fill_n(visited, 20101, false);
    std::fill_n(visited2, 20101, false);

    while (!s.empty())
    {
        int pos = s.top();
        s.pop();
        if (visited[pos])
        {
            if (!visited2[pos])
            {
                st.push(pos);
                visited2[pos] = true;
            }
            continue;
        }
        visited[pos] = true;
        s.push(pos);
        for (auto it = v[pos].begin(); it != v[pos].end(); it++)
        {
            s.push(*it);
        }
    }
    std::set<int> set;

    bool isValid = true;

    std::fill_n(visited, 20101, false);
    while (!st.empty())
    {
        s.push(st.top());
        st.pop();
        while (!s.empty())
        {
            int pos = s.top();
            s.pop();
            if (visited[pos])
                continue;
            visited[pos] = true;
            if(pos > 10000){
                if(set.find(pos-10000) != set.end()){
                    isValid = false;
                }
            }
            set.insert(pos);
            for (auto it = rv[pos].begin(); it != rv[pos].end(); it++)
            {
                s.push(*it);
            }
        }
        set.clear();
    }

    std::cout << ((isValid)?"1\n":"0\n");
    for(int i = 1; i <= N; i++){
        if(visited[i]){
            std::cout << "0 ";
        } else {
            std::cout << "1 ";
        }
    }

    return 0;
}