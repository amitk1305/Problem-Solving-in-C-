class Solution {
public:
bool matching( string s1, string s2)
{
    int i=0;
    for(i=0;i<s1.size();i++)
    {
    if(s1[i]!=s2[i])
    return 0;
    }
    if(s2[i]=='/')
    return 1;
    return 0;
}
    vector<string> removeSubfolders(vector<string>& folder) {
        int n=folder.size();
        vector<string>ans;
        sort(folder.begin(),folder.end());
        int start=0,end=1;
        while(end<n)
        {
            bool flag=0;
            string s1=folder[start],s2=folder[end];
            if(s1.size()<=s2.size())
            {
            flag=1;
            flag=matching(s1,s2);
            }
            if(flag)
            {
            end++;
            }
            else
            {
            ans.push_back(s1);
            start=end;
            end++;
            }
        }
        ans.push_back(folder[start]);
        return ans;
    }
};