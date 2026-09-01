class Solution {
    public int[] productExceptSelf(int[] nums) {
        //So... we cannot use /
        //We can store the previous multiplication, guarantees it does
        //not contain the current i, but what about values past i?
        int prev = 1;
        int next = 1;
        int[] output = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            output[i] = prev;
            prev *= nums[i];
        }

        for (int i = nums.length - 1; i >= 0; i--) {
            output[i] *= next;
            next *= nums[i];
        }

        return output;
    }
}  
