class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int> m1;
            for(int num: nums){
                    m1[num]++;
            }
            // vector<int> ans;
            int repeating,missing;
            for(int i=1;i<=nums.size();i++){
                    if(m1.find(i)==m1.end()){
                            missing=i;
                    }
                    else if(m1[i]==2){
                           repeating=i;
                    }
            }
            return {repeating,missing};
            // return ans;
    }
};