//USING DFS
class Solution {
private:
    bool dfs(int node,int col,int color[],vector<int>adj[]){
        color[node]=col;
        for(auto it : adj[node]){
            if(color[it]==-1){
                if(dfs(it,!col,color,adj)==false) return false;
            }
            else if(color[it]==col) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        int color[V];
        vector<int> adj[V];
        for (int i = 0; i < V; i++) {
            for (auto it : graph[i]) {
                adj[i].push_back(it);
            }
            color[i]=-1;
        }
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(dfs(i,0,color,adj)==false) return false;
            }
        }
        return true;

        

    }
};







//USING BFS

// class Solution {
// private:
//     bool check(int start,int V,vector<int>adj[],int color[]){
//         queue<int>q;
//         q.push(start);
//         color[start]=0;
//         while(!q.empty()){
//             int node=q.front();
//             q.pop();
            
//             for(auto it: adj[node]){
//                 if(color[it]==-1){
//                     color[it]=!color[node];
//                     q.push(it);
//                 }
//                 else if(color[it]==color[node]){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// public:
//     bool isBipartite(vector<vector<int>>& graph) {
//         int V=graph.size();
        
//         vector<int> adj[V];

//         for (int i = 0; i < V; i++) {
//             for (auto it : graph[i]) {
//                 adj[i].push_back(it);
//             }
//         }
//         int color[V];
//         for(int i=0;i<V;i++)
//             color[i]=-1;
//             for(int i=0;i<V;i++){
//                 if(color[i]==-1){
//                     if(check(i,V,adj,color)==false){
//                         return false;
//                     }
//                 }
//             }
//         return true;
//     }
// };