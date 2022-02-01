class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int biggest = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                
                
                if (grid[i][j] == 1) {
                    biggest = max(biggest, getIslandSize(grid, i, j));
                }
                
            }
        }
        return biggest;
    }
    
private:
    // Returns size of island; also sets island to -1 for all values in there
    int getIslandSize(vector<vector<int> > &grid, int i, int j) {
        
        // check out of bounds
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return 0;
        }
        
        // check current square is land
        if (grid[i][j] != 1) { 
            return 0; 
        }
        
        
        // DELETE ISLAND square we've just explored :)
        grid[i][j] = 0;
        
        // island size is this square plus any size on any side of the island
        return 1
            + getIslandSize(grid, i + 1, j)
            + getIslandSize(grid, i - 1, j)
            + getIslandSize(grid, i, j + 1)
            + getIslandSize(grid, i, j - 1);
            
    }
};