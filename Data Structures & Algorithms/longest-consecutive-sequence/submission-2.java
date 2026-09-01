class Solution {
    public int longestConsecutive(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        
        HashMap<Integer, Integer> numMap = new HashMap<>();
        for (int num : nums) {
            numMap.put(num, 1);
        }

        int maxSeq = 1;
        for (int num : numMap.keySet()) {
            System.out.println("First Num: " + num);
            int currSeq = 1;
            int currNum = num;
            while (numMap.containsKey(currNum - 1)) {
                currSeq += numMap.get(num - 1);
                if (numMap.get(num - 1) != 1) {
                    break;
                }
                currNum--;
            }

            numMap.put(num, currSeq);
            maxSeq = Math.max(maxSeq, currSeq);
        }

        return maxSeq;
    }
}
