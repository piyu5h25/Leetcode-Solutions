class Solution {
public:
     


    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
    unordered_multimap<int , pair<int ,int>> hash;

    for(int i=0;i<n-1;i++){

        for(int j=i+1;j<n;j++){

            hash.insert({ nums[i]*nums[j] , {nums[i] , nums[j]} });


        }
    }
   
   unordered_map<int ,int> seen;

   for(auto it : hash){
      
      if(it.first != seen.empty()){
        seen[it.first]++;
      } 
      else{
        seen[it.first] = 1;
      }

}
    
    int ans =0;

    for(auto kt : seen){
        int cnt = kt.second;

        if(cnt>1) ans += cnt*(cnt -1);
    }

 

   return ans*4;
       

    }
};