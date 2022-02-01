class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numIslands = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                
                if (grid[i][j] == '1') {
                    // island found! 
                    numIslands++;
                    deleteIsland(grid, i, j);
                }
            }
        }
        
        return numIslands;   
    }
private:
    // deletes island at location i, j
    void deleteIsland(vector<vector<char> > &grid, int i, int j) {
        
        // out of bounds
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return;
        }
        
        if (grid[i][j] != '1') { return; }
        
        grid[i][j] = '0';
        
        deleteIsland(grid, i + 1, j);
        deleteIsland(grid, i - 1, j);
        deleteIsland(grid, i, j + 1);
        deleteIsland(grid, i, j - 1);
        
        
    }
};