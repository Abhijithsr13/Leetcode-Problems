class Solution {
     private int[] delRow = { -1, 0, 1, 0 };
    private int[] delCol = { 0, 1, 0, -1 };

    private boolean isValid(int i, int j,
            int n, int m) {
        if (i < 0 || i >= n)
            return false;
        if (j < 0 || j >= m)
            return false;
        return true;
    }
        private void bfs(int[][] grid,
                     Queue<int[]> q,
                     boolean[][] vis) {
        int n = grid.length;
        int m = grid[0].length; 
        while(!q.isEmpty()) {
  
            int[] cell = q.poll();
            int row = cell[0];
            int col = cell[1];
            for(int i=0; i < 4; i++) {
                int nRow = row + delRow[i]; 
                int nCol = col + delCol[i]; 
                if(isValid(nRow, nCol, n, m) && 
                   grid[nRow][nCol] == 1 
                   && vis[nRow][nCol] == false) {
                    vis[nRow][nCol] = true;
                    q.add(new int[]{nRow, nCol});
                }
            }
        }
    }
    public int numEnclaves(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        Queue<int[]> q = new LinkedList<>();
        boolean[][] vis = new boolean[n][m];
        for(int i=0; i < n; i++) {
            for(int j=0; j < m; j++) {
                if((i == 0 || i == n-1 ||
                    j == 0 || j == m-1) &&
                    grid[i][j] == 1) {
                    
                    vis[i][j] = true;
                    q.add(new int[]{i, j});
                }
            }
        }
       
        bfs(grid, q, vis);
        int count = 0;
        for(int i=0; i < n; i++) {
            for(int j=0; j < m; j++){
                if(grid[i][j] == 1 && !vis[i][j])
                    count++;
            }
        }
        
        return count;
    }
}