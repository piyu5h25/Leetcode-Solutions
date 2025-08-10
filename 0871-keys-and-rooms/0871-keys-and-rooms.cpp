class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n= rooms.size();
        vector<bool>vis(n, 0);
        queue<int>q;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int i=0; i<rooms[curr].size(); i++){
                if(!vis[rooms[curr][i]]){
                    vis[rooms[curr][i]]=1;
                    q.push((rooms[curr][i]));
                }
            }
        }
        for(int i=0; i<n; i++){
            if(vis[i]==0)return false;
        }
        return true;

    }
};