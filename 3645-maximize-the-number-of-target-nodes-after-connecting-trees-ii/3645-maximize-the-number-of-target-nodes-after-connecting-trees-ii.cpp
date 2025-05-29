class Solution {
public:
void solve(int node,unordered_map<int,vector<int> >&adj1,int &oddf,int &evenf,int prnt,vector<int>&clr,int p){
         clr[node] = p; //this node have p color
         if(p==0){
            evenf++;
         }
         else{
           oddf++;
         }

         for(auto it:adj1[node]){
            if(it != prnt && clr[it] == -1){
                 //changing 1 to 0 or 0 to 1
                solve(it,adj1,oddf,evenf,node,clr, p^1);
               
            }
         }

}
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int,vector<int> >adj1;
        unordered_map<int,vector<int> >adj2;

        int n = edges1.size();
        int m = edges2.size();

        for(auto it:edges1){
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }
        for(auto it:edges2){
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }

        int oddf =0;
        int evenf =0;
        int oddS =0;
        int evenS =0;
        vector<int>clr(n+1,-1);
        int p = 0;
        solve(0,adj1,oddf,evenf,-1,clr,p);
        vector<int>b(m+1,-1);
        solve(0,adj2,oddS,evenS,-1,b,p);

        vector<int>ans(n+1,0);

        int maxi = max(evenS,oddS); 

        for(int i =0;i<=n;i++){
            if(clr[i] == 0){
                ans[i] = evenf + maxi; 
            }
            else{
                ans[i] = oddf + maxi;
            }
        }
return ans;

        
    }
};