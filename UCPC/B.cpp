#include <iostream>
#include <stack>

bool visited[50][50];
int input[50][50];
int output[50][50];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, M;
    std::cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            std::cin >> input[i][j];
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            std::cin >> output[i][j];
        }
    }

    bool flag = true;
    int cnt = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (visited[i][j])
                continue;
            std::stack<std::pair<int, int>> st;
            st.push({i, j});
            while (!st.empty())
            {
                int ii = st.top().first;
                int jj = st.top().second;
                st.pop();
                if (output[ii][jj] != output[i][j])
                    flag = false;
                for (int k = 0; k < 4; k++)
                {
                    int iii = ii + dx[k];
                    int jjj = jj + dy[k];
                    if (visited[iii][jjj] || input[iii][jjj] != input[i][j])
                        continue;
                    visited[iii][jjj] = true;
                    st.push({iii, jjj});
                }
            }

            cnt += (input[i][j] != output[i][j]);
        }
    }

    // std::cout << flag << " " << cnt << "\n";
    std::cout << ((flag && cnt <= 1) ? "YES\n" : "NO\n");

    return 0;
}