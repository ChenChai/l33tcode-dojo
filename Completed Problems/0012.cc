class Solution {
public:
    string intToRoman(int num) {
        // To hold the strings represented by different characters from start to finish
        vector<string> strings; 
        
        int place = 0;
        
        while (num > 0) {
            
            int digit = num % 10;
            num /= 10;
            place++;
            
            char oneChar;
            char fiveChar;
            char tenChar;
            
            // Figure out which characters to use based on digit place
            switch (place) {
                case 1:
                    oneChar = 'I';
                    fiveChar = 'V';
                    tenChar = 'X';
                    break;
                case 2:
                    oneChar = 'X';
                    fiveChar = 'L';
                    tenChar = 'C';
                    break;
                case 3:
                    oneChar = 'C';
                    fiveChar = 'D';
                    tenChar = 'M';
                    break;
                case 4:
                    oneChar = 'M';
                    break;
            }
            
            
            string digitToRoman;
            
            // Convert digit to the chars we selected since
            // digits always convert the same just with different characters
            switch (digit) {
                case 1:
                    digitToRoman = { oneChar };
                    break;                
                
                case 2:
                    digitToRoman = { oneChar, oneChar };
                    break;                
                case 3:
                    digitToRoman = { oneChar, oneChar, oneChar };
                    break;                
                case 4:
                    digitToRoman = { oneChar, fiveChar };
                    break;                
                case 5:
                    digitToRoman = { fiveChar };
                    break;                
                case 6:
                    digitToRoman = { fiveChar, oneChar };
                    break;                
                case 7:
                    digitToRoman = { fiveChar, oneChar, oneChar };
                    break;                
                case 8:
                    digitToRoman = { fiveChar, oneChar, oneChar, oneChar };
                    break;                
                case 9:
                    digitToRoman = { oneChar, tenChar };
                    break;
            }
            
            strings.push_back(digitToRoman);
        }
        
        // Join strings together since we made them in reverse order
        string ans = "";
        for (int i = strings.size() - 1; i >= 0; i--) {
            ans.append(strings[i]);
        }
        
        return ans;
    }
};