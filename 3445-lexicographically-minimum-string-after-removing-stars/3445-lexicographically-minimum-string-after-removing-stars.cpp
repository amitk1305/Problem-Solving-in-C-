class Solution {
public:
    string clearStars(string s) {

        int n = s.length();

        string ans = "";

        vector<bool> isPresent(n,true); // last main batayega ki index ka element deleted hai ya answer main rakhna hai
        unordered_map <char,list<int>> charToLatestIndex; // har character ka latest index store karega

        priority_queue<char,vector<char>,greater<char>> smallestCharToLeft; // peeche ka smallest character dega

        for(int i=0 ; i<n ; i++){

            if(s[i]!='*'){
                smallestCharToLeft.push(s[i]); // character pushed into min heap to give smallest character value when needed
                charToLatestIndex[s[i]].push_back(i); // iss character ka latest index 'i' ho jayega
            }

            else{
                isPresent[i] = false; // '*' ko answer main include nahi karna
                char ch = smallestCharToLeft.top(); // left main sabse chota non-deleted character
                smallestCharToLeft.pop(); // left ka sabse chota element will be deleted
                int index = charToLatestIndex[ch].back(); // index of smallest char to left of '*'
                charToLatestIndex[ch].pop_back(); // removing the latest index value of char because wo index delete kr diya
                isPresent[index] = false; // index element deleted toh ye element ab final answer main nhi hoga
            }

        }


        for(int i=0 ; i<n ; i++){
            if(isPresent[i]){ // saare non-deleted elements(excluding stars)
                ans+=s[i];
            }
        }

        return ans;
        
    }
};