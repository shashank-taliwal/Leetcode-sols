class StockSpanner {
public:
    int i=-1;
    stack<pair<int,int>> stk;
    StockSpanner() {}
    
    int next(int price) {
        i++;
        while(!stk.empty() and stk.top().first<=price){
            stk.pop();
        }
        if(stk.empty()){
            stk.push({price,i});
            return i+1;
        }
        int ans=i-stk.top().second;
        stk.push({price,i});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */