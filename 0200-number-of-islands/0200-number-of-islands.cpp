class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0,r=grid.size(),c=grid[0].size();
        int dir_r[]={1,-1,0,0};  // Just to make dirctions easy
        int dir_c[]={0,0,1,-1};  // Down,Up,Right,Left
        vector<vector<bool>> vis(r,vector(c,false));

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='0' || vis[i][j])  // If we get water or we already visited then we don't need to do anything
                    continue;
                queue<pair<int,int>> q;
                q.push({i,j});
                ans++;
                vis[i][j]=true;
                while(!q.empty()){
                    auto pre=q.front();
                    q.pop();
                    for(int d=0;d<4;d++){
                        int qr= pre.first + dir_r[d];
                        int qc= pre.second + dir_c[d];
                        if(qr<0 || qr >= r || qc<0 || qc>= c){ // Land reched the side that means it got water and we need to do nothing then
                            continue;
                        } 
                        if(grid[qr][qc]=='0') continue;  // If we get water then also we dont do nothing
                        if(vis[qr][qc]) continue;  // If we already visited then also we dont do nothing
                        q.push({qr,qc});
                        vis[qr][qc]=true;
                    }                    
                }
            }
        } 
        return ans;        
    }
};