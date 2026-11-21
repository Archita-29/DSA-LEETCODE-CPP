class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> origAdj(n);
        for (int i = 1; i < n; ++i) {
            origAdj[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;
        vector<int> closest(26, -1);
        auto reassignDFS = [&](auto& self, int u) -> void {
            int ch = s[u] - 'a';
            if (u != 0 && closest[ch] != -1) {
                newParent[u] = closest[ch];
            }

            int prev = closest[ch];
            closest[ch] = u;

            for (int v : origAdj[u]) {
                self(self, v);
            }

            closest[ch] = prev; 
        };
        reassignDFS(reassignDFS, 0);

        // Build adjacency list for the modified tree
        vector<vector<int>> finalAdj(n);
        for (int i = 1; i < n; ++i) {
            finalAdj[newParent[i]].push_back(i);
        }
        
        vector<int> ans(n, 1);
        auto sizeDFS = [&](auto& self, int u) -> int {
            int sz = 1;
            for (int v : finalAdj[u]) {
                sz += self(self, v);
            }
            return ans[u] = sz;
        };

        sizeDFS(sizeDFS, 0);
        return ans;
    }
};