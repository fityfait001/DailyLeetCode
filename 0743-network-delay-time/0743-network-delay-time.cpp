class Solution {
public:
    void dfs(int k,vector<vector<pair<int,int>>> &adj,vector<int>&distance){
        for(auto it:adj[k]){
            int node=it.first;
            int wt=it.second;
        
            if(distance[node]>distance[k]+wt){
                distance[node]=distance[k]+wt;
                dfs(node,adj,distance);
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>distance(n+1,INT_MAX);
        distance[k]=0;
        dfs(k,adj,distance);

        int ans=0;
        for(int i=1;i<=n;i++){
            if(distance[i]==INT_MAX) return -1;

            ans=max(ans,distance[i]);
        }
        return ans;
        

    }
};