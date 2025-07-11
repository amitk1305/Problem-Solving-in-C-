class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> res(n, 0);
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for(int i=0; i<n; i++){
            freeRooms.push(i);
        }
        sort(meetings.begin(), meetings.end());
        priority_queue<vector<long>, vector<vector<long>>, greater<>> roomFree;
        for(int i=0; i<meetings.size(); i++){
            if(freeRooms.empty()){
                vector<long> rF=roomFree.top();
                roomFree.pop();
                long endTime=rF[0];
                long room=rF[1];
                if(endTime<=meetings[i][0]){
                    freeRooms.push(room);
                    while(!roomFree.empty() && roomFree.top()[0]<=meetings[i][0]){
                        freeRooms.push(roomFree.top()[1]);
                        roomFree.pop();
                    }
                    i--;
                }
                else{
                    res[room]++;
                    endTime+=(meetings[i][1]-meetings[i][0]);
                    roomFree.push({endTime, room});
                }
            }
            else{
                while(!roomFree.empty() && roomFree.top()[0]<=meetings[i][0]){
                    freeRooms.push(roomFree.top()[1]);
                    roomFree.pop();
                }
                long room=freeRooms.top();
                freeRooms.pop();
                vector<long> rF;
                rF.push_back(meetings[i][1]);
                rF.push_back(room);
                roomFree.push(rF);
                res[room]++;
            }
        }
        int mx=INT_MIN;
        int ans=0;
        for(int i=0; i<n; i++){
            cout << res[i] << " ";
            if(res[i]>mx){
                ans=i;
                mx=res[i];
            }
        }
        return ans;
    }
};