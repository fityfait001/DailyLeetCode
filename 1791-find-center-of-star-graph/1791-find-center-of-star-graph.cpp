class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int x1=edges[0][0];
        int y1=edges[0][1];
        int x2=edges[1][0];
        int y2=edges[1][1];
        if(x1==x2 || x1==y2){
            return x1;
        }
        return y1;
    }
};