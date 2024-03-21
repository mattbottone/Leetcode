class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0, left = 0;

        for (int right = 1; right < prices.size(); right++) {
            if (prices[right] < prices[left]) left = right;
            else if (prices[right] - prices[left] > max) max = prices[right] - prices[left];
        }
        return max;
    }
};
