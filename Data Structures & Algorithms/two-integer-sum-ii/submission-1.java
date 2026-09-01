class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int left = 0;
        int right = numbers.length - 1;
        int twoSum = numbers[left] + numbers[right];
        while (twoSum != target) {

            if (twoSum > target) {
                right--;
            }

            else {
                left++;
            }
            
            twoSum = numbers[left] + numbers[right];
        }
        int[] idxArr = {left + 1, right + 1};
        return idxArr;
    }
}
