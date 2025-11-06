class Solution {
public:

    struct DSU {
        vector<int> parent, sz;
        DSU(int n) {
            parent.resize(n + 1);
            sz.assign(n + 1, 1);
            for (int i = 1; i <= n; i++) parent[i] = i;
        }
        int find(int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        }
        void unite(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) return;
            if (sz[a] < sz[b]) swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    };

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);

        // Step 1: Build components
        for (auto &e : connections) {
            dsu.unite(e[0], e[1]);
        }

        // Step 2: Each component will have a min-heap of its stations
        vector<vector<int>> heaps(c + 1); 
        vector<bool> online(c + 1, true);

        // Put every station into its component heap
        for (int i = 1; i <= c; i++) {
            int root = dsu.find(i);
            heaps[root].push_back(i);
        }

        // Convert to min-heaps
        for (int i = 1; i <= c; i++) {
            if (!heaps[i].empty()) {
                make_heap(heaps[i].begin(), heaps[i].end(), greater<int>());
            }
        }

        vector<int> ans;

        // Step 3: Process queries
        for (auto &q : queries) {
            int type = q[0], x = q[1];
            int root = dsu.find(x);

            if (type == 1) {
                // Query: resolve maintenance check
                if (online[x]) {
                    ans.push_back(x);
                } else {
                    // Lazy delete offline stations
                    while (!heaps[root].empty() && !online[heaps[root].front()]) {
                        pop_heap(heaps[root].begin(), heaps[root].end(), greater<int>());
                        heaps[root].pop_back();
                    }

                    if (heaps[root].empty()) ans.push_back(-1);
                    else ans.push_back(heaps[root].front());
                }
            }
            else {
                // Station goes offline
                online[x] = false;
            }
        }

        return ans;
    }
};