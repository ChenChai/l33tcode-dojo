class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // move elements in nums1 to back of nums1
        for (int i = m-1; i >= 0; i--) {
            nums1[i + n] = nums1[i];
        }
        
        int i = 0;
        int index1 = n;
        int index2 = 0;
        
        while (index1 < n + m || index2 < n) {
        
            if (index1 == n + m) {
                // nums1 done; add rest of nums2
                nums1[i] = nums2[index2];
                index2++;
            } else if (index2 == n) {
                // nums2 done; add rest of nums1.
                nums1[i] = nums1[index1]; 
                index1++;
            } else if (nums1[index1] < nums2[index2]) {
                nums1[i] = nums1[index1]; 
                index1++;
            } else {
                nums1[i] = nums2[index2];
                index2++;
            }   
            i++;
        }
    }
};