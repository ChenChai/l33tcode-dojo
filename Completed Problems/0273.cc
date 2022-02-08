class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) { return "Zero"; }
        // Since english numbers are in sort of 3-digit packages, we'll use that to our advantage!
        string ans;
        int place = 0;
        while (num > 0) {
            
            int threeDigit = num % 1000;
            num /= 1000;
            
            if (threeDigit == 0) { place += 3; continue; }
            
            string threeDigitModifier = convertThreeDigit(threeDigit);
            
            string threeDigitName = "";
            switch (place) {
                case 0:
                    threeDigitName = "";
                    break;
                case 3:
                    threeDigitName = "Thousand";
                    break;
                case 6:
                    threeDigitName = "Million";
                    break;
                case 9: 
                    threeDigitName = "Billion";
                    break;
            }
            
            ans = threeDigitModifier 
                + (threeDigitName.empty() ? "" : " ")
                + threeDigitName
                + (ans.empty() ? "" : " ")
                + ans;
            
            place += 3;
        }
        
        return ans;
    }
    
private:
    // Transforms a number between 0-999 to a string
    // returns empty string if num == 0
    string convertThreeDigit(int num) {
        
        string ans = "";
        
        int place = 0;
        
        bool teens = false;
        while (num > 0) {
            int digit = num % 10;
            num /= 10;
            place++;
            
            if (place == 1 && num % 10 == 1) {
                // Special case for teens
                // Skip directly to second place
                teens = true;
                num /= 10;
                place++;
            }
            
            vector<string> englishDigits;
            
            switch (place) {
                case 1:
                    englishDigits = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
                    break;
                case 2:
                    englishDigits = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
                    // special case for teens 
                    // Digit in this case still represents the ones spot
                    if (teens) {
                        englishDigits = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
                    }
                    
                    break;
                case 3:
                    englishDigits = {"", "One Hundred", "Two Hundred", "Three Hundred", "Four Hundred", "Five Hundred", "Six Hundred", "Seven Hundred", "Eight Hundred", "Nine Hundred"};
                    break;
            }
            
            if (!englishDigits.at(digit).empty()) {
                ans = englishDigits.at(digit) + (ans.empty() ? "" : " ") + ans;
            }
            
        }
        
        return ans;
    }
};