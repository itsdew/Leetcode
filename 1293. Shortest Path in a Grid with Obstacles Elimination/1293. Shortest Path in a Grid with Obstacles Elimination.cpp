//Author: Devendra Uraon 
class Solution {
public:
    int shortestPath(std::vector<std::vector<int>>& grid, int k) {
        const std::vector<int> dirs{0, 1, 0, -1, 0};
        const int m = grid.size(), n = grid[0].size();
        std::vector<std::vector<int>> seen(m, vector<int>(n, INT_MAX));
        std::queue<std::tuple<int, int, int>> queue_{{{0, 0, 0}}}; 
        int steps = 0;
        seen[0][0] = 0;
        while (!queue_.empty()) {
            int size = queue_.size();
            while (size-- > 0) {
                int cx = 0, cy = 0, co = 0;
                std::tie(cx, cy, co) = queue_.front(); queue_.pop();
                if (cx == n - 1 && cy == m - 1) return steps;
                for (int i = 0; i < 4; i++) {
                    const int x = cx + dirs[i];
                    const int y = cy + dirs[i + 1];
                    if (x < 0 || y < 0 || x >= n || y >= m) continue;
                    const int o = co + grid[y][x];
                    if (o >= seen[y][x] || o > k) continue;            
                    seen[y][x] = o;
                    queue_.emplace(x, y, o);
                }
            }
            steps++;
        }
        return -1;
    }
};
