class Solution {
    private boolean bfs(int start, int[][] graph, int[] color) {
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(start);
        color[start] = 0;

        while (!queue.isEmpty()) {
            int node = queue.poll();
            for (int neighbor : graph[node]) {
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    queue.offer(neighbor);
                } else if (color[neighbor] == color[node]) {
                    return false;  // Conflict found
                }
            }
        }
        return true;
    }
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int[] color = new int[n];
        Arrays.fill(color, -1);  // -1 means unvisited

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!bfs(i, graph, color)) {
                    return false;
                }
            }
        }
        return true;
    }

}