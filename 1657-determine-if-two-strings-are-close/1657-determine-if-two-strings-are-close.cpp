class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> freq1(26), freq2(26);
        for(auto chr : word1){
            freq1[chr - 'a']++;
        }
        for(auto chr : word2){
            freq2[chr - 'a']++;
        }
        for(int indx = 0; indx < 26; indx++){
            if(freq1[indx] >0 && freq2[indx] == 0)return false;
            else if(freq2[indx] > 0  && freq1[indx] == 0)return false;
        }
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        for(int indx = 0; indx < 26; indx++){
            if(freq1[indx] != freq2[indx]){
                return false;
            }
        }
        return true;
    }
};