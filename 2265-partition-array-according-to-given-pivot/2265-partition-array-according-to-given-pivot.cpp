class Solution {
public:
    
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>lesser, greater, equal;
        for(int num: nums){
            if(num< pivot){
                lesser.push_back(num);
            }
            else if(num> pivot){
                greater.push_back(num);
            }
            else{
                equal.push_back(num);
            }
        }
        for(int num: equal){
            lesser.push_back(num);
        }
        for(int num: greater){
            lesser.push_back(num);
        }
        return lesser;
    }

};