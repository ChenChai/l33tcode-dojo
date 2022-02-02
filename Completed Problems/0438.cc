class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) { 
            return {};
        }
        
        vector<int> seen(26, 0);
        vector<int> required(26, 0);
        vector<int> ans;
        
        int index = 0;
        for (const char &c : p) {
            required[c - 'a']++;
            seen[s[index] - 'a']++;
            index++;
        }
        if (seen == required) {
            ans.push_back(index - p.size());
        }   
        for (; index < s.size(); index++) {

      
            seen[s[index] - 'a']++;
            seen[s[index - p.size()] - 'a']--;

            if (seen == required) {
                ans.push_back(index - p.size() + 1);
            }      
        } 
        
        
        
        return ans;
    }
};