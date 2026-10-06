class Solution {
    public int characterReplacement(String s, int k) {
        int j = 0;
        Map<Character, Integer> charMap = new HashMap<>();
        int totalCount = 0;
        int largest = 0;

        for (int i = 0; i < s.length(); i++) {
            
            charMap.put(s.charAt(i), charMap.getOrDefault(s.charAt(i), 0) + 1);
            totalCount++;

            Map.Entry<Character, Integer> maxEntry = Collections.max(
                charMap.entrySet(), 
                Map.Entry.comparingByValue()
            );

            while ((totalCount - maxEntry.getValue()) > k) {
                charMap.put(s.charAt(j), charMap.get(s.charAt(j)) - 1);
                totalCount--;
                j++;
                maxEntry = Collections.max(
                    charMap.entrySet(), 
                    Map.Entry.comparingByValue()
                );
            }

            largest = Math.max(largest, totalCount);
        }
        return largest;
    }
}
