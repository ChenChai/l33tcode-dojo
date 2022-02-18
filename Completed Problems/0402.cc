class Solution {
public:
    string removeKdigits(string num, int k) {
        
        string ans;
        
        // Loop until we run out of digits to remove
        // or we should remove all remaining integers
        int i;
        for (i = 0; i < (int) num.size(); i++) {
            // our heuristic for removal
            // of numbers is decreasing numbers
            // if the next number is smaller we should
            // take it out!
            
            char current = num.at(i);
            if (i + 1 >= num.size()) { break; }
            char next = num.at(i+1);
            
            // remove a character!
            //cout << i << " i" << "checking " << current << " num " << num << endl;
            if (current > next && k > 0) {
                //cout << "removing " << current << endl;
                k--;
                num.erase(num.begin() + i);
                i -= 2; // move back to recheck the string essentially
                if (i < 0) { i = -1; }
                
            }
            
        }
        // erase extra stuff
        for (;k > 0; k--) {
            num.erase(num.end()-1);
        }
        
        ans = num;

        
        
        // remove extra leading zeroes
        while (ans.front() == '0') {
            ans.erase(ans.begin());
        } 
        // if we don't add nums we automcatically
        // remove them from ans
        if (ans.size() == 0) { return "0"; }        
        
        return ans;
    }
};
