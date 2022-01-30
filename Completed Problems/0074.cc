class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowLength = matrix[0].size();
        int columnLength = matrix.size();
        
        int size = rowLength * columnLength;
        
        // Binary search just with indices fixed up
        // If this was C we could just use normal binary search
        
        int low = 0;
        int high = size - 1;
        
        while (low <= high) {
            
            int index = low + (high - low) / 2;
            int search = matrix[index / rowLength][index % rowLength];
            
            if (search < target) {
                low = index + 1;
            } else if (search > target) {
                high = index - 1;
            } else {
                return true;
            }
        }
        
        return false;
    }
};