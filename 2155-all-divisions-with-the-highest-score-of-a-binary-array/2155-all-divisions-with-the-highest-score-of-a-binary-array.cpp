class Solution {
        int getScore(int a, int b){
                return a+b;
        }
        void debug(vector<int> debug_scores){
                for(int score: debug_scores){
                        cout<<score<<" ";
                }
        }
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int left_cnt0=0,left_cnt1=0,right_cnt0=0,right_cnt1=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
                if(nums[i]){
                        right_cnt1++;
                }
                else{
                        right_cnt0++;
                }
        }
            vector<int> divison_scores;
            int ptr=0;
            while(ptr<n){
                    int score=getScore(left_cnt0,right_cnt1);
                    divison_scores.push_back(score);
                    if(nums[ptr]==0){
                            left_cnt0++;
                    }
                    else{
                            right_cnt1--;
                    }
                    ptr++;
            }
            divison_scores.push_back(getScore(left_cnt0,right_cnt1));
            vector<int> ans;
            int index=0;
            // debug(divison_scores);
            int max_score=*max_element(divison_scores.begin(),divison_scores.end());
            for(int score: divison_scores){
                    if(score==max_score){
                            ans.push_back(index);
                    }
                    index++;
            }
            return ans;
    }
};