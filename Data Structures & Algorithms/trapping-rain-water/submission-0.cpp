class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        int maxLeft = 0;
        int maxRight = 0;
        int i = 0;
        int j = height.size()-1;
        while(i <= j){
            if(height[i] < height[j]){
                maxLeft = max(maxLeft, height[i]);
                water += maxLeft - height[i];
                i++;
            }else{
                maxRight = max(maxRight, height[j]);
                water += maxRight - height[j];
                j--;
            }
        }
        return water;
    }
};
