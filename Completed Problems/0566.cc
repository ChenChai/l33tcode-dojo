class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (mat.empty()) {return mat;}
        int m = mat.size(); // original num rows
        int n = mat[0].size();
        
        // matrices will hold different amounts of values, can't reshape!
        if (n * m != r * c) { return mat; }
        
        // Create new matrix, initializing the size.
        vector<vector<int> > newMat(r, vector<int>(c));
        
        int row = 0; 
        int column = 0;
        
        for (int oldRow = 0; oldRow < m; oldRow++) {
            for (int oldCol = 0; oldCol < n; oldCol++) {
                newMat[row][column] = mat[oldRow][oldCol];
                
                // Move to next element
                column++;
                if (column >= c) { column = 0; row++; }
            }
        }
        
        
        
        return newMat;
    }
};