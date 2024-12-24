class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size(),m=edges2.size();
        n++,m++;
        int temp1=0,temp2=0;
        vector<int>indegre1(n,0),indegre2(m,0);
        vector<vector<int>>adj1(n),adj2(m);
        for(auto it:edges1){
            indegre1[it[0]]++;
            indegre1[it[1]]++;
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }
        for(auto it:edges2){
            indegre2[it[0]]++;
            indegre2[it[1]]++;
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }
        int level1=0,level2=0;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegre1[i]==1)q.push(i);
        }
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                auto node=q.front();
                q.pop();
                for(auto it:adj1[node]){
                    indegre1[it]--;
                    if(indegre1[it]==1)q.push(it);
                }
            }
            if(q.size()!=0){
                level1++;
                temp1=2*level1;
            }
            if(s==2 && q.empty()){
                level1++;
                temp1++;
            }
        }
        for(int i=0;i<m;i++){
            if(indegre2[i]==1)q.push(i);
        }
        while(!q.empty()){
   
            int s=q.size();
            for(int i=0;i<s;i++){
                auto node=q.front();
                q.pop();
                for(auto it:adj2[node]){
                    indegre2[it]--;
                    if(indegre2[it]==1)q.push(it);
                }
            }
            if(!q.empty()){
                level2++; 
                temp2=level2*2;
            }
            if(q.empty()&& s==2){
                level2++;
                temp2++;
            }
        }
        // cout<<level1<<" "<<level2;
        if(n==2)level1=1;
        if(m==2)level2=1;
        temp1=max(temp1,temp2);
        return max(level1+level2+1,temp1);
    }
};