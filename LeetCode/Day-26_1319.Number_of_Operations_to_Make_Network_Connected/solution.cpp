class disjoint_set {
private:
    vector<int> parent, size;

public:
    disjoint_set(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find_parent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = find_parent(parent[node]);
    }

    void union_by_size(int u, int v) {
        int pv = find_parent(v);
        int pu = find_parent(u);
        if (pv == pu) return;

        if (size[pv] < size[pu]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        } else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }

    int count_components(int n) {
        set<int> st;
        for (int i = 0; i < n; i++) st.insert(find_parent(i));
        return st.size();
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        disjoint_set ds(n);
        int redundant = 0;

        for (auto connection : connections) {
            if (ds.find_parent(connection[0]) == ds.find_parent(connection[1])) {
                redundant++;
            } else {
                ds.union_by_size(connection[0], connection[1]);
            }
        }

        int components = ds.count_components(n);
        if (components - 1 <= redundant) return components - 1;
        return -1;
    }
};
