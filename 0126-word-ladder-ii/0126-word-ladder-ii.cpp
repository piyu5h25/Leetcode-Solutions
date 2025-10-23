class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (!st.count(endWord)) return {};

        unordered_map<string, vector<string>> parents;
        unordered_map<string, int> dist;
        queue<string> q;
        
        q.push(beginWord);
        dist[beginWord] = 0;
        int wordLen = beginWord.size();
        int minDist = INT_MAX;

        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int currDist = dist[word];
            if (currDist > minDist) break; // stop exploring longer paths

            for (int i = 0; i < wordLen; i++) {
                string temp = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    if (!st.count(temp)) continue;

                    if (!dist.count(temp)) {
                        dist[temp] = currDist + 1;
                        q.push(temp);
                    }
                    if (dist[temp] == currDist + 1) {
                        parents[temp].push_back(word);
                    }
                    if (temp == endWord) {
                        minDist = currDist + 1;
                    }
                }
            }
        }

        vector<vector<string>> ans;
        if (!dist.count(endWord)) return ans;

        vector<string> path = {endWord};
        function<void(string)> backtrack = [&](string word) {
            if (word == beginWord) {
                vector<string> curr = path;
                reverse(curr.begin(), curr.end());
                ans.push_back(curr);
                return;
            }
            for (auto& p : parents[word]) {
                path.push_back(p);
                backtrack(p);
                path.pop_back();
            }
        };

        backtrack(endWord);
        return ans;
    }
};
