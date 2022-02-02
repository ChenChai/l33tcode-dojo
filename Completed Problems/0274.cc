class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
                
        int maxH = 0;
        for (int i = citations.size() -1; i >= 0; i--) {
            
            int num = citations[i];
            
            int h = (citations.size()) - i;
            
            if (num >= h && (i == 0 || citations[i-1] <= h)) {
                maxH = max(maxH, h);
            }
        }
        
        return maxH;
    }
};