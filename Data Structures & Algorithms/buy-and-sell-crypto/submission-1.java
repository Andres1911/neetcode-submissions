class Solution {
    public int maxProfit(int[] prices) {
        int minIndex = 0;
        int profit = 0;
        for (int i = 0; i < prices.length; i++) {
            if (prices[i] < prices[minIndex]) {
                minIndex = i;
            }
            profit = Math.max(profit, prices[i] - prices[minIndex]);
        }

        return profit;
    }
}
