class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> grid(n * n + 1, -1);
        int idx = 1;
        bool leftToRight = true;

        for (int r = n - 1; r >= 0; --r) {
            if (leftToRight) {
                for (int c = 0; c < n; ++c) {
                    grid[idx++] = board[r][c];
                }
            } else {
                for (int c = n - 1; c >= 0; --c) {
                    grid[idx++] = board[r][c];
                }
            }
            leftToRight = !leftToRight;
        }

        vector<bool> visited(n * n + 1, false);
        queue<pair<int, int>> q;
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [curr, moves] = q.front();
            q.pop();

            if (curr == n * n) {
                return moves;
            }

            for (int dice = 1; dice <= 6 && curr + dice <= n * n; ++dice) {
                int nextSquare = curr + dice;
                if (grid[nextSquare] != -1) {
                    nextSquare = grid[nextSquare];
                }
                if (!visited[nextSquare]) {
                    visited[nextSquare] = true;
                    q.push({nextSquare, moves + 1});
                }
            }
        }

        return -1;
    }
};
