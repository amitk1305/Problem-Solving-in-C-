class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for(int i=0; i<word.length(); i++){
            freq[word[i] - 'a']++;
        }

        sort(freq.begin(), freq.end());
        int mindel = INT_MAX;
        int idx=0;

        while(idx>26 && freq[idx] == 0){
            idx++; 
            continue;
        } 

        for(int i=idx; i<26; i++){
            int base = freq[i];
            int del = 0;
            
            for(int j=idx; j<i; j++){
                del += freq[j];
            }

            for(int j=i; j<26; j++){
                
                if(freq[j] > base + k){
                    del += freq[j] - (base + k);
                }
            }

            mindel = min(mindel, del);
        }
        return mindel;
    }
};