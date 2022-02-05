class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int, int> > q;
        
        bool noOranges = true;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // rotting orange!!
                // add to queue
                if (grid[i][j] == 2) {
                    noOranges = false;
                    q.push(pair<int, int>(i, j));
                }
                
                if (grid[i][j] == 1) {
                    noOranges = false;
                }
            }
        }
        
        if (noOranges) { return 0; }
        
        // run bfs
        vector<vector<int> > directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int maxDay = -1;
        while (!q.empty()) {
            int i = get<0>(q.front());
            int j = get<1>(q.front());
            q.pop();

            if (!isValid(i, j, grid)) {
                // out of bounds
                continue;
            }

            if (grid[i][j] == 0) {
                // empty space, no possible thing to follow
                continue;
            }
            
            if (grid[i][j] >=2) { maxDay = max(grid[i][j], maxDay);}
            
            for (int dir = 0; dir < 4; dir++) {
                // search in each direction
                int i2 = i + directions[dir][0];
                int j2 = j + directions[dir][1];

                if (isValid(i2, j2, grid)) {
                    if (grid[i2][j2] == 1) {
                        grid[i2][j2] = grid[i][j] + 1;
                        q.push(pair<int, int>(i2, j2));
                    }
                }
                
            }
            
            
        }
        
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // fresh orange!!
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }        
        return maxDay - 2;
    }
    
private:
    bool isValid(int i, int j, vector<vector<int> >& grid) {
        return !(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size());
    }
};