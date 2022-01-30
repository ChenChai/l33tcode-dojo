class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        // Solve using a monotonic stack (in decreasing order) 
        // to figure out the next pillar shorter than the current one for 
        // every index
        // then, solve with that! Since rectangles always have to start at the top haha
        // O(n) hopefully
        
        // monotonic stack hint was great
        
        // Create TWO arrays indicating forward and reverse order monotonic stacks
        
        vector<int> nextSmallerPillar(heights.size());
        vector<int> prevSmallerPillar(heights.size());
        
        // monotonic stack
        // Need to store a pair of int, int to represent vector and size lol
        // first: value // second: index
        stack<pair<int, int> > monoStack;
        
        for (int i = 0; i < heights.size(); i++) {
            int x = heights[i];
            
            while (!monoStack.empty() && x <= get<0>(monoStack.top())) {
                monoStack.pop();
            }
            
            // found the previous smaller element!
            // could be itself
            prevSmallerPillar[i] = monoStack.empty() ? -1 : get<1>(monoStack.top());
            monoStack.push({x, i});
        }
        
        while (!monoStack.empty()) { monoStack.pop(); }

        
        for (int i = heights.size() - 1; i >= 0; i--) {
            int height = heights[i];
            
            while (!monoStack.empty() && height <= get<0>(monoStack.top())) {
                monoStack.pop();
            }
            
            // found the next smaller element!
            nextSmallerPillar[i] = monoStack.empty() ? -1 : get<1>(monoStack.top());
            monoStack.push({height, i});
        }
         
        int largest = 0;
        for (int i = 0; i < heights.size(); i++) {
            int sizeToRight = nextSmallerPillar[i] == -1 ? heights.size() - i -1 : nextSmallerPillar[i] - i - 1; 
            int sizeToLeft = prevSmallerPillar[i] == -1 ? i : i - prevSmallerPillar[i] - 1; 

            int totalSize = (sizeToLeft + sizeToRight + 1) * heights[i];
            largest = max(largest, totalSize);
            // cout << totalSize << ' '; 
        }
        
       //cout << endl << "nextsmaller";
       //for (int n : nextSmallerPillar) { cout << " " << n; } cout << endl;
       //cout << "prevsmaller";
       //for (int n : prevSmallerPillar) { cout << " " << n; } cout << endl;

        return largest;
    }
};