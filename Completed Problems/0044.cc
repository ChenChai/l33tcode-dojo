class Solution {
public:
    bool isMatch(string s, string p) {
        unordered_map<string, bool> memo;
        
        string_view sView(s);
        string_view pView(p);
        return isMatchHelper(sView, pView, memo);
    }
    
private:
    // Divide and conquer algorithm to test every possible value :)
    bool isMatchHelper(string_view s, string_view p, unordered_map<string, bool> &memo) {
        // fast way to hash all the chars here lol
        string spot = { (char) s.size(), ' ', (char) p.size()};
        
        if (memo.find(spot) != memo.end()) {
            return memo[spot];
        }
        
        // handle the empty case 
        if (s.size() == 0 || p.size() == 0) {
            // we've reached the end of both strings!
            if (s.size() == 0 && p.size() == 0) { 
                memo[spot] = true;
                return true; 
            }
            
            // Ran out of matches
            if (p.size() == 0) {
                memo[spot] = false;
                return false;
            }
            
            // S size is zero, only valid if all values are '*'
            for (int i = 0; i < p.size(); i++) {
                if (p[i] != '*') { 
                    memo[spot] = false;
                    return false; 
                }
            }
            memo[spot] = true;
            return true;
        }
        
        string_view sPlus(s);
        string_view pPlus(p);
            
        sPlus.remove_prefix(1);
        pPlus.remove_prefix(1);
        
        // Case 1: wildcard character
        if (p[0] == '?') {
            // Continue on!

            bool ans = isMatchHelper(sPlus, pPlus, memo);
            memo[spot] = ans;
            return ans;
        } else if (p[0] == '*') {
            // if the next one is also a star, then skip
            
            if (p.size() > 1 && p[1] == '*') { 
                bool ans = isMatchHelper(s, pPlus, memo);
                memo[spot] = ans;
                return ans;
            }
            
            // sequence wildcard character
            bool ans = isMatchHelper(s, pPlus, memo) // consume the wildcard
                || isMatchHelper(sPlus, p, memo); // don't consume the wildcard
            memo[spot] = ans;
            return ans;
        } else {
            if (s[0] == p[0]) {
                bool ans = isMatchHelper(sPlus, pPlus, memo);
                memo[spot] = ans;
                return ans;
            } else {
                memo[spot] = false;
                return false;
            }
        }
        
    }
};