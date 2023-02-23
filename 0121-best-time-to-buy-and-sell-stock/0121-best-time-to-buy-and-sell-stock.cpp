class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit=0;
            int cp=prices[0];
            int sp=prices[0];
            for(int i=1;i<prices.size();i++){
                    if(prices[i]<cp){
                            cp=prices[i];
                            sp=prices[i];
                    }
                    else if(prices[i]>sp){
                            sp=prices[i];
                    }
                    max_profit=max(max_profit, sp-cp);
            }
            return max_profit;
    }
};