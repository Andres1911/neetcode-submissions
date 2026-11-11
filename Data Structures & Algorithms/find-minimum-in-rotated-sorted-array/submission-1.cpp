class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid_point = (left + right) / 2;
            if (nums[mid_point] > nums[right]) {
                left = mid_point + 1;
            }
            else {
                right = mid_point;
            }
        }
        return nums[left];
    }

    /*

    Alright, we can take the midpoint, what happens when the array is rotated? and the rotation is before:
    midpoint < right && right < left <- Notice only can happen when the breakingpoint is left of midpoint )midpo

    What happens when it is to the right?

    midpoint > left (left to midpoint is the only sorted part of the array)
    Is this if and only if?

    Assume break is left of midpoint, then midpoint < right (sorted part), and the max is between left and midpoint, as (right < left). Therefore, midpoint < left, which is a contradiction.

    So this is enough, idea is to discard the "sorted" part at each iteration.
    Now what happens when mid_point = min? Impossible to tell, ideally we can clamp it as left < right and return left since right would be midpoint, and left midpoint + 1

    So just return left

    */
};
