class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for (int row = 0; row < 9; row++) {

            for (int col = 0; col < 9; col++) {

                char current = board[row][col];

                if (current == '.') {
                    continue;
                }

                int boxIndex = (row / 3) * 3 + (col / 3);

                // Duplicate check
                if (rows[row].count(current) ||
                    cols[col].count(current) ||
                    boxes[boxIndex].count(current)) {

                    return false;
                }

                // Insert into sets
                rows[row].insert(current);
                cols[col].insert(current);
                boxes[boxIndex].insert(current);
            }
        }

        return true;
    }
};
        
                
               