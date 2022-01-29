class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        // initialize first row
        vector<vector<int> > triangle(1, vector<int>(1, 1));
        
        for (int i = 1; i < numRows; i++) {
            
            // Create new vector for new row, as well as first element in row 
            // (which is 1)
            triangle.push_back(vector<int>(1, 1));
            
            for (int j = 1; j < i; j++) {
                
                triangle[i].push_back(triangle[i-1][j] + triangle[i-1][j-1]);
            }
            
            // fill in last element of row
            triangle[i].push_back(1);
        }
        
        return triangle;
    }
};