class Solution {
    public int trap(int[] height) {

        int maxIndex = 0;
        for (int i = 0; i < height.length; i++) {
            if (height[i] > height[maxIndex]) {
                maxIndex = i;
            }
        }

        int left = 0;
        int right = 0;

        while (left < maxIndex && height[left] == 0) {
            left++;
        }

        int totArea = 0;
        while (left < maxIndex) {
            right = left + 1;
            int currArea = 0;
            while (right < maxIndex && height[left] > height[right]) {
                currArea += (height[left] - height[right]);
                right++;
            }
            totArea += currArea;
            left = right;
        }

        right = height.length - 1;
        while (right > maxIndex) {
            left = right - 1;
            int currArea = 0;

            while (left > maxIndex && height[right] > height[left]) {
                currArea += (height[right] - height[left]);
                left--;
            }

            totArea += currArea;
            right = left;
        }

        return totArea;
    }
}
