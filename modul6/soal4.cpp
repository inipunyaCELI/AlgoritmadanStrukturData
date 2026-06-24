#include <bits/stdc++.h>
using namespace std;

int R, C, sr, sc, fr, fc;
vector<vector<int>> grid;
vector<vector<bool>> visited;
int count_paths = 0;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y)
{
    if (x == fr && y == fc)
    {
        count_paths++;
        return;
    }
    for (int d = 0; d < 4; d++)
    {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx >= 0 && nx < R && ny >= 0 && ny < C && grid[nx][ny] == 0 && !visited[nx][ny])
        {
            visited[nx][ny] = true;
            dfs(nx, ny);
            visited[nx][ny] = false;
        }
    }
}

int main()
{
    cin >> R >> C;
    grid.assign(R, vector<int>(C));
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> grid[i][j];
    cin >> sr >> sc >> fr >> fc;

    visited.assign(R, vector<bool>(C, false));
    visited[sr][sc] = true;
    dfs(sr, sc);

    cout << count_paths << endl;
    return 0;
}