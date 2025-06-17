// Approach:
// We initialize a queue with all 0s in the matrix and mark all 1s as -1 (unprocessed).
// Using multi-source BFS, we expand from all 0s simultaneously and assign distance to each 1 by adding 1 at each level.
// Each cell is processed once when it's converted from -1 to a non-negative number.

// Time Complexity: O(m × n)
// Each cell is enqueued and processed at most once.

// Space Complexity: O(m × n)
// In the worst case, all cells could be in the queue (especially if all are 0s).

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<vector<int>> q ;
        int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}}; 
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(mat[i][j] == 1)
                    mat[i][j] = -1;
                else
                    q.push({i,j});

            }
        }
        int dist = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;++i){
                vector<int> ind = q.front();
                q.pop();
                for(int d=0;d<4;++d){
                    int nr = ind[0] + dirs[d][0];
                    int nc = ind[1] + dirs[d][1];
                    if(nr > -1 && nc > -1 && nr < m && nc <n && mat[nr][nc] == -1){
                        q.push({nr,nc});
                        mat[nr][nc]=dist;
                    }
                }
            }
            dist++;
        }
        return mat;
    }
};
