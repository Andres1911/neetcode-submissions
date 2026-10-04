class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        Set<List<Integer>> result = new HashSet<>();

        for (int i = 0; i < nums.length - 2; i++) {
            int anchor_value = nums[i];

            int left = i + 1;
            int right = nums.length - 1;
            
            while (left < right) {
                int right_value = nums[right];
                int left_value = nums[left];
                int current_sum = right_value + left_value + anchor_value;

                if (current_sum == 0) {
                    result.add(List.of(right_value, left_value, anchor_value));
                    right -= 1;
                    left += 1;
                }

                else if (current_sum < 0) {
                    left += 1;
                }

                else {
                    right -= 1;
                }
            }
        }

        return new ArrayList<>(result);
    }
}
