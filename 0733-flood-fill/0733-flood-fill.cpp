class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>&ans,vector<vector<int>>&image,int newColor,int iniColor){
        ans[row][col]=newColor;
        int n=image.size();
        int m=image[0].size();
        int dRow[]={-1,1,0,0};
        int dCol[]={0,0,-1,1};

        for(int i=0;i<4;i++){
            int nRow=row+dRow[i];
            int nCol=col+dCol[i];

            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && image[nRow][nCol]==iniColor && ans[nRow][nCol]!=newColor)
            dfs(nRow,nCol,ans,image,newColor,iniColor);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor=image[sr][sc];
        vector<vector<int>> ans=image;
        dfs(sr,sc,ans,image,color,iniColor);
        return ans;
    }
};