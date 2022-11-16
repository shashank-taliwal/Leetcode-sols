class Solution {
    int getArea(vector<int>& height, int left, int right){
        return min(height[left],height[right])*(right-left);
    }
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int n=height.size();
        int left=0,right=n-1;
        while(left<right){
            ans=max(ans,getArea(height,left,right));
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return ans;
    }
};