/*
Approach:
It performs Breadth-First Search (BFS) starting from pixel (sr, sc).
Changes all connected pixels with the same original color to the new color.
Uses a Queue to explore neighbors in 4 directions (up, down, left, right).

Time Complexity (TC)
Let:
m = number of rows
n = number of columns
Worst-case time complexity: O(m * n)

Space complexity:  O(m * n)
  */

class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int x = image[sr][sc];
        int m = image.length;
        int n = image[0].length;
        if(x == color) return image;
        int [][]dirs = {{1,0},{0,1},{-1,0},{0,-1}};
        Queue<Integer> q = new LinkedList<>();
        q.add(sr);
        q.add(sc);
        image[sr][sc] = color;
        while(!q.isEmpty()){
            int cr = q.poll();
            int cc = q.poll();
            for(int[] dir : dirs){
                int nr = cr + dir[0];
                int nc = cc + dir[1];
                if(nr > -1 && nc > -1 && nr < m && nc < n && image[nr][nc] == x){
                    q.add(nr);
                    q.add(nc);
                    image[nr][nc] = color;
                }
            }
        }
        return image;
    }
}
