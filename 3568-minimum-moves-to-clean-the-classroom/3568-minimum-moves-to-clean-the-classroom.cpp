class Solution {
public:
    class state {
    public:
        int row;
        int col;
        int energy;
        int mask;

        state(int r, int c, int e, int m) {
            row = r;
            col = c;
            energy = e;
            mask = m;
        }
    };

    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int row = 0, col = 0;
        int total = 0;

        // Assign an ID to every litter cell
        vector<vector<int>> litter(m, vector<int>(n, -1));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                char cell = classroom[i][j];

                if (cell == 'S') {
                    row = i;
                    col = j;
                }

                if (cell == 'L') {
                    litter[i][j] = total;
                    total++;
                }
            }
        }

        // All litter collected
        int collected = (1 << total) - 1;

        queue<state> q;
        q.push(state(row, col, energy, 0));

        // [row][col][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m, vector<vector<vector<bool>>>(
                   n, vector<vector<bool>>(energy + 1,
                                           vector<bool>(1 << total, false))));

        visited[row][col][energy][0] = true;

        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int moves = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size-- > 0) {
                // queue.pop() returns void, so get front first
                state current = q.front();
                q.pop();

                // All litter collected
                if (current.mask == collected) {
                    return moves;
                }

                // Can't move anymore
                if (current.energy == 0) {
                    continue;
                }

                for (auto& d : dir) {
                    int newRow = current.row + d[0];
                    int newCol = current.col + d[1];

                    // Outside grid
                    if (newRow < 0 || newRow >= m || newCol < 0 ||
                        newCol >= n) {
                        continue;
                    }

                    // Wall
                    if (classroom[newRow][newCol] == 'X') {
                        continue;
                    }

                    int newEnergy = current.energy - 1;
                    int newMask = current.mask;

                    char cell = classroom[newRow][newCol];

                    // Collect litter
                    if (cell == 'L') {
                        int l = litter[newRow][newCol];
                        newMask |= (1 << l);
                    }

                    // Recharge
                    if (cell == 'R') {
                        newEnergy = energy;
                    }

                    if (visited[newRow][newCol][newEnergy][newMask]) {
                        continue;
                    }

                    visited[newRow][newCol][newEnergy][newMask] = true;

                    q.push(state(newRow, newCol, newEnergy, newMask));
                }
            }

            // Increase moves after processing one BFS level
            moves++;
        }

        return -1;
    }
};