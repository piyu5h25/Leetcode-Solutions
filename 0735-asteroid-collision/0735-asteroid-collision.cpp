class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        list<int> st;
        
        for(int i = 0; i < n; i++){
            if(asteroids[i] > 0){
                st.push_back(asteroids[i]);
            }
            else {
                while(!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])){
                    st.pop_back(); // Remove smaller positive asteroids
                }
                
                if(!st.empty() && st.back() == abs(asteroids[i])){
                    st.pop_back(); // Both asteroids explode
                }
                else if(st.empty() || st.back() < 0){
                    st.push_back(asteroids[i]); // Add the negative asteroid
                }
            }
        }
        
        // Convert list to vector for the return
        return vector<int>(st.begin(), st.end());
    }
};

