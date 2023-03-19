class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
            map<int,int> freqHashMap;
            int left=0,right=0;
            while(right<nums.size()){
                    int freqOfVal=0;
                    if(freqHashMap.find(nums[right])!=freqHashMap.end()){
                            freqOfVal=freqHashMap[nums[right]];
                    }
                    if(freqOfVal<2){
                            nums[left]=nums[right];
                            left++;
                            freqHashMap[nums[right]]++;
                    }
                    right++;
            }
            return left;
    }
};