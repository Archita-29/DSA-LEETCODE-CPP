class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowMasks;
        
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (col >= 2 && col <= 9) {
                rowMasks[row] |= (1 << (col - 2));
            }
        }
        
        int maxGroups = (n - rowMasks.size()) * 2;
        
        int leftBlock   = 0b00001111; 
        int middleBlock = 0b00111100; 
        int rightBlock  = 0b11110000; 
        
        for (const auto& [row, mask] : rowMasks) {
            bool left   = (mask & leftBlock) == 0;
            bool right  = (mask & rightBlock) == 0;
            bool middle = (mask & middleBlock) == 0;
            
            if (left && right) {
                maxGroups += 2;
            } else if (left || right || middle) {
                maxGroups += 1;
            }
        }
        
        return maxGroups;
    }
};