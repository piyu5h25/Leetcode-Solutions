class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n=arr.size();
        if(n==1){
            return;
        }
        int l = 0, mid = 0, r = n-1;
        while(mid<=r){
            if(arr[mid]==0){
                swap(arr[l], arr[mid]);
                l++;
                mid++;
            }
            else if(arr[mid]==1){
                mid++;
            }
            else{
                swap(arr[mid], arr[r]);
                r--;
            }

        }
        return;
    }
};