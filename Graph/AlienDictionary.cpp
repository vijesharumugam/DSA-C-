// https://www.geeksforgeeks.org/problems/alien-dictionary/1

class Solution {
  public:
    string findOrder(vector<string> &words) {
        vector<vector<int>> adj(26);
        vector<int> ind(26, -1);

        for (int i = 0; i < words.size() - 1; i++) {
            string str1 = words[i];
            string str2 = words[i + 1];
            int n = min(str1.size(), str2.size());
            bool found = false;

            for (int j = 0; j < n; j++) {
                if (str1[j] != str2[j]) {
                    int u = str1[j] - 'a';
                    int v = str2[j] - 'a';
                    adj[u].push_back(v);
                    if (ind[u] == -1) ind[u] = 0;
                    if (ind[v] == -1) ind[v] = 0;
                    ind[v]++;
                    found = true;
                    break;
                }
            }

            if (!found && str1.size() > str2.size())
                return "";
        }

        for (auto &w : words)
            for (char c : w)
                if (ind[c - 'a'] == -1) ind[c - 'a'] = 0;
        queue<int> q;
        int v = 0;
        for (int i = 0; i < 26; i++) {
            if (ind[i] == 0) q.push(i);
            if (ind[i] != -1) v++;
        }

        string ans = "";
        while (!q.empty()) {
            int a = q.front();
            q.pop();
            ans += char(a + 'a');
            for (auto j : adj[a]) {
                if (--ind[j] == 0)
                    q.push(j);
            }
        }


        if (ans.size() == v) return ans;
        
        return "";
    }
};
