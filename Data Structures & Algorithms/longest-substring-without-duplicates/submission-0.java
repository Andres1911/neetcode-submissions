class Solution {
    public int lengthOfLongestSubstring(String s) {
        int left = 0;
        HashSet<Character> candidates = new HashSet<>();
        int maxWindow = 0;

        for (int i = 0; i < s.length(); i++) {
            while (candidates.contains(s.charAt(i))) {
                candidates.remove(s.charAt(left));
                left++;
            }

            candidates.add(s.charAt(i));
            maxWindow = Math.max(i - left + 1, maxWindow);
        }
        return maxWindow;
    }
}
