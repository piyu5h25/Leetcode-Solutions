class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        int l = 0, r = n-1;
        int leftmx=0, rightmx=0;
        int ans = 0;


        while(l<=r){
            leftmx = max(leftmx, height[l]);
            rightmx = max(rightmx, height[r]);

            if(leftmx < rightmx){
                ans += leftmx - height[l];
                l++;
            }
            else{
                ans += rightmx - height[r];
                r--;
            }

        }
        return ans;
    }
};