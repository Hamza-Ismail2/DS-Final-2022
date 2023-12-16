#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& grid, int r, int c){
    int row = grid.size();
    int col = grid[0].size();
    if(r >= row || c >= col || r < 0 || c < 0 || grid[r][c] == '0' || grid[r][c] == '2')
        return;
    if(grid[r][c] == 1){
        grid[r][c] = 0;
        dfs(grid, r-1, c);
        dfs(grid, r+1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
    }
    return;
}
int numIslands(vector<vector<int>>& grid) {
    int r = grid.size();
    int c = grid[0].size();
    int ans = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(r < 0 || c < 0 || grid[i][j] == 0)
                continue;
            if(grid[i][j] == 1){
                ans++;
                grid[i][j] = '0';
                dfs(grid, i-1, j);
                dfs(grid, i+1, j);
                dfs(grid, i, j+1);
                dfs(grid, i, j-1);
            }
        }
    }
    return ans;
}


int main() {

    

}