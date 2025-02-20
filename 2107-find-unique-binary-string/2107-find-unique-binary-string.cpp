class Solution {
public:
#define rep(i, a, b) for (int i = a; i < b; i++)
    string findDifferentBinaryString(vector<string>& nums) {
      string ans ="";
      rep(i,0,nums.size()){
        // basic thinking ye hai ki nyi string bnao aur diagonal check kro
        /* [1,0]
           [0,1]
           to jo char hoga wo pehle 1 ko flip kr dega aur 0 kr dega ab doosre ke 2nd element ko krega check or usko change krega jisse ki pehle row ka jo element change kiya wo exact mach na krjaye 2nd row se*/
        char ch = (nums[i][i]=='0')? '1':'0';

        
        ans.push_back(ch);
      }  
      return ans;
    }
};