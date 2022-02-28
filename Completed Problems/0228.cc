class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) { return {}; }
        vector<string> ans;
        
        int rangeStart = nums[0];
        int rangeEnd = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            
            int cur = nums[i];
            
            if (cur > rangeEnd + 1) {
                ans.push_back(make_range(rangeStart, rangeEnd));
                rangeStart = cur;
                rangeEnd = cur;
            } else {
                rangeEnd = cur;
            }
        }
        ans.push_back(make_range(rangeStart, rangeEnd));
        
        return ans;
    }
    
private:
    string make_range(int start, int end) {
        if (start == end) { return to_string(start); } 
        else { return to_string(start) + "->" + to_string(end); }
    }
};
