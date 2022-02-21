class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compareLower);
        
        // Decrement remaining as we go down. 
        int remaining = intervals.size();
        
        int biggestUpper = intervals[0][1];
        
        // As we loop, the lower bound of intervals we're
        // seeing will increase. Thus, any interval 
        // that has an upper bound lower than the biggest
        // we've seen so far will be covered for sure!
        for (int i = 1; i < intervals.size(); i++) {
            int lower = intervals[i][0];
            int upper = intervals[i][1];
            //cout << "checking " << lower << "," << upper << endl;
            
            if (upper <= biggestUpper) {
                //cout << "decreased remaining!"<<endl;
                remaining--;
            }
            
            if (biggestUpper <= upper) {
                
                biggestUpper = upper;
                // Previous interval is overlapped by current one!!
                if (intervals[i-1][0] == lower) {
                    remaining--;
                }
            }
        }
        
        return remaining;
    }
    
private:
    // returns comparison based on lower bound of interval
    static bool compareLower(vector<int>& l, vector<int>& r) {
        
        if (l[0] == r[0]) {
            return l[1] > r[1]; // sort in descending order of upper intervals for lowest bottom intervals
        }
        return l[0] < r[0];
    }
};
