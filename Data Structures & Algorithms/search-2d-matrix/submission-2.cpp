class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int num_cols = matrix[0].size();
        int num_rows = matrix.size();
        int right = num_cols * num_rows;

        while(left < right) {
            int mid = (left + right) / 2;
            int row = mid / num_cols;
            int col = mid % num_cols;
            if (matrix[row][col] == target) {
                return true;
            }
            else if (matrix[row][col] < target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return false;
    }
};
