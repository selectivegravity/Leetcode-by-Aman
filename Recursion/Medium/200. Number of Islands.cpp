//https://leetcode.com/problems/number-of-islands/

/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/

class Solution {
public:
    void solve(vector<vector<char>>& grid,vector<vector<bool>>& visited,int r,int c,int i,int j){
        if(i<0 || j<0 || i>=r || j>=c){
            return;
        }
        if(!visited[i][j] && grid[i][j]=='1'){
            visited[i][j]=1;
            //front
            solve(grid,visited,r,c,i+1,j);
            //back
            solve(grid,visited,r,c,i-1,j);
            //up
            solve(grid,visited,r,c,i,j+1);
            //down
            solve(grid,visited,r,c,i,j-1);
        }
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int count=0;
        vector <vector<bool>> visited(r,vector<bool>(c));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count++;
                    solve(grid,visited,r,c,i,j);
                }
            }
        }
        return count;
    }
};
