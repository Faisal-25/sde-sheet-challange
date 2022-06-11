class Solution {
    public int maxProfit(int[] prices) {
         int profit = Integer.MIN_VALUE;
        int minDay = Integer.MAX_VALUE;
        for(int i = 0;i<prices.length;i++){
            if(prices[i]<minDay){
                minDay = prices[i];
            }
          profit = Math.max(profit,prices[i]-minDay);
        }
     return profit;
    }
}