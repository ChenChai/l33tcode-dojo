class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        
        int i1 = 0, i2 = 0;
        
        vector<int> ans;
        
        while (i1 < nums1.size() && i2 < nums2.size()) {
            
            int x1 = nums1[i1];
            int x2 = nums2[i2];
            
            if (x1 == x2) {
                ans.push_back(x1);
                i1++;
                i2++;
            } else if (x1 < x2) {
                i1++;
            } else {
                i2++;
            }
        }
        
        return ans;
    }
};