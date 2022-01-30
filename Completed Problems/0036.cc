class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<bool> numbers (9, false);
        
        // Check rows
        for (int i = 0; i < 9; i++) { 
            
            for (int j = 0; j < 9; j++) {
                
                if (board[i][j] == '.') { continue; }
                
                // repeated number
                if (numbers[board[i][j] - '1'] == true) {
                    //print(numbers);

                   // cout << "repeat detected in rows" << i << j;
                    return false;
                }
                
                numbers[board[i][j] - '1'] = true;
            }
            //print(numbers);
            clear(numbers);
        }
        
        // Check columns
        for (int i = 0; i < 9; i++) { 
            
            for (int j = 0; j < 9; j++){
                
                if (board[j][i] == '.') { continue; }
                
                // repeated number
                if (numbers[board[j][i] - '1'] == true) {
                   // cout << "repeat detected in cols" << i << j;
                    return false;
                }
                
                numbers[board[j][i] - '1'] = true;
            }
            
            clear(numbers);
        }
        
        cout << "squares" << endl;
        // Check 3x3 squares
        for (int bigRow = 0; bigRow < 3; bigRow++) {
            for (int bigCol = 0; bigCol < 3; bigCol++) {
                
                
                //inside the 3x3 square
                for (int i = 3*bigRow; i < 3 + (3*bigRow); i++) { 

                    for (int j = 3*bigCol; j < 3 + (3*bigCol); j++){

                        if (board[i][j] == '.') { continue; }

                        // repeated number
                        if (numbers[board[i][j] - '1'] == true) {
                            //print(numbers);

                            //cout << "repeat detected in big squares" << bigRow << bigCol << i << j;

                            return false;
                        }

                        numbers[board[i][j] - '1'] = true;
                    }

                }
                // print(numbers);

                clear(numbers);

                
            }
        }
        
        return true;
    }
    
private:
    void clear(vector<bool> &v) {
        for (int i = 0; i < v.size(); i++) {
            v[i] = false;
        }
    }
    
    void print(vector<bool> &v) {
        cout << "[";
        
        for (int i = 0; i < v.size(); i++) {
            if (v[i]) { 
                cout << i + 1 << ' ';
            }
        }
        cout << "]" << endl;
        
    }
};