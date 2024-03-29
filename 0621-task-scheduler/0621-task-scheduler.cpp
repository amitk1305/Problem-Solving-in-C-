class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        int N = tasks.size();        
        int counter[26] = {0};
        int maxF = 0; // max_freq
        int maxFc = 0; // no of ch having max_freq
        
        for (int i = 0; i < N; i++) {
            counter[tasks[i] - 'A']++;
        }
        
        for (int x : counter) {
            if (maxF == x) {
                maxFc++;
            }
            if (maxF < x) {
                maxF = x;
                maxFc = 1;
            }
        }
        
        int gaps = maxF - 1; // number of gaps required
        
        int gaps_len = k - (maxFc - 1); // number of ch that can be fit in partition gaps
        
        int avail_slot = gaps * gaps_len; // empty slots = number of gaps * gaps_len
        
        int avail_task = N - maxF * maxFc;
        
        int idles = max(0, avail_slot - avail_task); // place available tasks in total available
        // slots and rest as idle
        
        return N + idles;
        
    }
};