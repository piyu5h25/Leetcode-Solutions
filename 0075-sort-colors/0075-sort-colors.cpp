class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n=arr.size();
        if(n==1){
            return;
        }
        for(int i=0; i<n; i++){
            bool swapNeeded = false;    
            for(int j=0; j<n-1; j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j], arr[j+1]);
                    swapNeeded = true;
                }
            }
            if(swapNeeded == false)break;
        }
    }
};