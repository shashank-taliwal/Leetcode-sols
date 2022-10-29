struct Flower{
        int plantTime;
        int growTime;
        Flower(int plantTime_, int growTime_){
                //Constructor
                plantTime=plantTime_;
                growTime=growTime_;
        }
};
class Solution {
        static bool comp(struct Flower& flr1, struct Flower& flr2){
                return flr1.growTime>flr2.growTime;
        }
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<struct Flower> garden;
        int n=plantTime.size();
        for(int i=0;i<n;i++){
                garden.push_back(Flower(plantTime[i],growTime[i]));
        }
            sort(garden.begin(),garden.end(),comp);
            int ans=0;
            int prefixPlantTime=0;
            for(int i=0;i<n;i++){
                    prefixPlantTime+=garden[i].plantTime;
                    ans=max(ans,prefixPlantTime+garden[i].growTime);
            }
            // ans+=garden.back().growTime;
            return ans;
    }
};