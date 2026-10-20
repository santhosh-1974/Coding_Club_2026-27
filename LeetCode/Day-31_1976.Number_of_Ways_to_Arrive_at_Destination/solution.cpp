class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        vector<long long> dist(n, LLONG_MAX), path(n, 0);
        priority_queue<pair<long long, long long>,
                       vector<pair<long long, long long>>,
                       greater<pair<long long, long long>>> pq;
        pq.push({0, 0});
        dist[0] = 0;
        path[0] = 1;
        const long long mod = 1e9 + 7;

        while (!pq.empty()) {
            long long d = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            if (d > dist[node]) {
                continue;
            }

            for (auto road : adj[node]) {
                long long nextNode = road.first;
                long long nextDist = d + road.second;
                if (dist[nextNode] > nextDist) {
                    dist[nextNode] = nextDist;
                    pq.push({nextDist, nextNode});
                    path[nextNode] = path[node];
                } else if (dist[nextNode] == nextDist) {
                    path[nextNode] = (path[nextNode] + path[node]) % mod;
                }
            }
        }
        return path[n - 1] % mod;
    }
};
