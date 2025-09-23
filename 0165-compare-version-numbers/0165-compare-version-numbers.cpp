class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n = v1.length(), m = v2.length();
        int i=0, j =0;

        while(i<n || j<m){
            long long num1 = 0, num2 = 0;

            while(i<n and v1[i]!= '.'){
                num1 = num1*10 + (v1[i]-'0');
                i++;
            }
            i++; // skipping the dot

            while(j<m && v2[j]!='.'){
                num2 = num2*10 + (v2[j]-'0');
                j++;

            }
            j++; // skipping the dot

            
            if(num1<num2)return -1;
            if(num1>num2)return 1;
        }
        
        return 0;
    }
};