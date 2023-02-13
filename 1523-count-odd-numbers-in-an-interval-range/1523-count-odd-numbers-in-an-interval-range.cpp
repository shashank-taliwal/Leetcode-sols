class Solution {
public:
    int countOdds(int low, int high) {
        int diff=high-low;
            if(diff%2){
                    return (diff+1)/2;
            }
            int ans=diff/2;
            // return diff/2;
            if(low%2){
                    ans++;
            }
            return ans;
    }
};