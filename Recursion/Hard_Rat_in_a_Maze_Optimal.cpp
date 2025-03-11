/*
Consider a rat placed at position (0, 0) in an n x n square matrix mat. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

The matrix contains only two possible values:

0: A blocked cell through which the rat cannot travel.
1: A free cell that the rat can pass through.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell. In case of no path, return an empty list.+

The task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.

Return the final result vector in lexicographically smallest order.

Examples:

Input: mat[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
Output: ["DDRDRR", "DRDDRR"]
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
Input: mat[][] = [[1, 0], [1, 0]]
Output: []
Explanation: No path exists and the destination cell is blocked.
Input: mat = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
Output: ["DDRR", "RRDD"]
Explanation: The rat has two possible paths to reach the destination: 1. "DDRR" 2. "RRDD", These are returned in lexicographically sorted order.
Constraints:
2 ≤ mat.size() ≤ 5
0 ≤ mat[i][j] ≤ 1

*/
// User function template for C++

class Solution 
{
    public:
    void solve(int i, int j, vector<vector<int>> &mat, int n, vector<string> &ans, string move, vector<vector<int>> &vis)
    {
        if(i == (n-1) && j == (n-1))
        {
            ans.push_back(move);
            return;
        }
        //downward
        if(i+1<n && !vis[i+1][j] && mat[i+1][j] == 1)
        {
            vis[i][j] = 1;
            solve(i+1, j, mat,n,ans, move + 'D', vis);
            vis[i][j] = 0;
        }
        // left
        if(j-1>=0 && !vis[i][j-1] && mat[i][j-1] == 1)
        {
            vis[i][j] = 1;
            solve(i, j-1, mat,n,ans, move + 'L', vis);
            vis[i][j] = 0;
        }
        // right
        if(j+1<n && !vis[i][j+1] && mat[i][j+1] == 1)
        {
            vis[i][j] = 1;
            solve(i, j+1, mat,n,ans, move + 'R', vis);
            vis[i][j] = 0;
        }
        // Upward
        if(i-1>=0 && !vis[i-1][j] && mat[i-1][j] == 1)
        {
            vis[i][j] = 1;
            solve(i-1, j, mat,n,ans, move + 'U', vis);
            vis[i][j] = 0;
        }
        
        
    }
  public:
    vector<string> findPath(vector<vector<int>> &mat) 
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int> (n, 0)); // important
        /*
        [
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0]
        ]

        */
        if(mat[0][0] == 1) 
        {
            solve(0,0,mat,n,ans,"", vis);
        }
        return ans;
        // code here
    }
};

/*
Time Complexity: O(4^(m*n)), because on every cell we need to try 4 different directions.

Space Complexity:  O(m*n), Maximum Depth of the recursion tree(auxiliary space).
*/
