// You are given two string arrays words1 and words2.

// A string b is a subset of string a if every letter in b occurs in a including multiplicity.

// For example, "wrr" is a subset of "warrior" but is not a subset of "world".
// A string a from words1 is universal if for every string b in words2, b is a subset of a.

// Return an array of all the universal strings in words1. You may return the answer in any order.

 

// Example 1:

// Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
// Output: ["facebook","google","leetcode"]
// Example 2:

// Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
// Output: ["apple","google","leetcode"]
 

// Constraints:

// 1 <= words1.length, words2.length <= 104
// 1 <= words1[i].length, words2[i].length <= 10
// words1[i] and words2[i] consist only of lowercase English letters.
// All the strings of words1 are unique.

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> maxfreq(26, 0);

        for(const string& word:words2){
            vector<int> freq(26, 0);
            for(char c:word){
                freq[c - 'a']++;
            }
            for(int i=0;i<26;i++){
                maxfreq[i] = max(maxfreq[i], freq[i]);
            }
        }

        //check for each word in words1
        for(const string& word: words1){
            vector<int> freq(26, 0);
            for(char c:word){
                freq[c - 'a']++;
            }

            bool isUniversal=true;

            for(int i=0;i<26;i++){
                if(freq[i]<maxfreq[i]){
                    isUniversal=false;
                    break;
                }
            }
            if(isUniversal){
                ans.push_back(word);
            }
        }

        return ans;
    }
};
