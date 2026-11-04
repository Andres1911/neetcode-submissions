class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();

        while (left < right) {
            int mid = (right + left) / 2;
            //cout<<"Mid value: "<<mid<<" Left: "<<left<<" Right: "<<right;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return -1;
    }
};
