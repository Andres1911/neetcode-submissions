class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> candidates;
        int left = 0;
        int right = 0;
        vector<int> result;

        while (right < nums.size()) {
            while (!candidates.empty() && candidates[0] < left) {
                candidates.pop_front();
            }

            while (!candidates.empty() && nums[right] > nums[candidates.back()]) {
                candidates.pop_back();
            }

            candidates.push_back(right);

            if (right >= k - 1) {
                result.push_back(nums[candidates[0]]);
                left++;
            }
            
            right++;
        }
        return result;
    }
};
