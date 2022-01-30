class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int high = numbers.size() - 1;
        int low = 0;
        
        
        do {
            
            if (numbers[high] + numbers[low] > target) {
                // added up to above target, start decreasing high
                high--;
            } else if (numbers[high] + numbers[low] < target) {
                // added up to below target, start increasing low
                low++;
            } else {
                
                // numbers add up to target; return found value!!
                return { low+1, high+1 };
            }
        } while (high > low);
        
            
        // no value found. 
        // should not reach this.
        return {};
    }
};