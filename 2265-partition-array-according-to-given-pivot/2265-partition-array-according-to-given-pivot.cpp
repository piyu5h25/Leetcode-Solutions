class Solution {
public:
    
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n= nums.size();
        vector<int>result(n);
        int l=0, r = n-1;
        for(int i=0, j = n-1;  i<n; ++i, --j){
            if(nums[i]<pivot){
                result[l]= nums[i];
                l++;
            }
            if(nums[j]>pivot){
                result[r]= nums[j];
                r--;
            }
        }
        while(l<=r){
            result[l]=pivot;
            l++;
        }
        return result;
    }

};