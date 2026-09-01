class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        /*I mean you could sort by frequency?
        // 1. Count elements
        // 2. Sort by frequency
        // 3. Return top K frequent O(n log n)
        // ========================
        
        There is another way
        1. Count elements
        2. Iterate using a priority heap
        3. Pop k elements from heap O(n)
        */
        Map<Integer, Long> counts = Arrays.stream(nums)
            .boxed()
            .collect(Collectors.groupingBy(num -> num, Collectors.counting()));
        
        PriorityQueue<Integer> minHeap = new PriorityQueue<>(
            (a, b) -> Long.compare(counts.get(a), counts.get(b))
        );
        for (Map.Entry<Integer, Long> entry : counts.entrySet()) {
            if (minHeap.size() < k) {
                minHeap.add(entry.getKey());
            }
            else {
                if (entry.getValue() > counts.get(minHeap.peek())) {
                    minHeap.poll();
                    minHeap.add(entry.getKey());
                }
            }
        }
        int[] result = minHeap.stream().mapToInt(Integer::intValue).toArray();
        return result;
    }
}
