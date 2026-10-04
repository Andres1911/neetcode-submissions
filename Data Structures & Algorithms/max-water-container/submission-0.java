class Solution {
    public int maxArea(int[] heights) {
        int maxArea = 0;
        int left = 0;
        int right = heights.length - 1;

        while (left < right) {
            int width = right - left;
            int currArea = Math.min(heights[left], heights[right]) * width;
            if (currArea > maxArea) {
                maxArea = currArea;
            }

            if (heights[left] < heights[right]) {
                left += 1;
            }

            else {
                right -= 1;
            }
            
        }

        return maxArea;
    }
}
