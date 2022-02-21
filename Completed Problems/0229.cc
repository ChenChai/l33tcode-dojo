class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        
        set<int> ans;
        for (int n : nums) {
            if (hash.find(n) == hash.end()) { hash[n] = 0; }
            hash[n]++;
            
            if (hash[n] > nums.size() / 3) { ans.insert(n); }
        }
        
        return vector<int>(ans.begin(), ans.end());
    }
};
