class Solution {
public:
    int maxArea(vector<int>& height) {
        
        // Greedy algorithm to look for higher bars as we move inwards
        int low = 0;
        int high = height.size() - 1;
        
        int maxVol = 0;
        while (low < high) {
            
            // Find volume of container
            maxVol = max(maxVol, (high - low) * min(height[high], height[low]));
            
            // Only possible bigger container is if we choose a higher wall
            // as we move in 
            if (height[low] < height[high]) {
                low++;
            } else {
                high--;
            }
        }
        
        return maxVol;
    }
};