https://leetcode.com/problems/find-common-characters/
/*
Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

 

Example 1:

Input: words = ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: words = ["cool","lock","cook"]
Output: ["c","o"]
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists of lowercase English letters.
*/

class Solution {
public:
    
string _compare(string &s1,string &s2){
    map <char,pair<int,int>> m;
    for(int i=0;i<s1.size();i++){
        m[s1[i]].first++;
    }
    for(int i=0;i<s2.size();i++){
        m[s2[i]].second++;
    }
    string ans="";
    for(auto it=m.begin();it!=m.end();it++){
        int n=min((it->second).first,(it->second).second);
        for(int i=0;i<n;i++){
            ans+=(it->first);
        }
    }
    return ans;
}
    
vector<string> commonChars(vector<string>& words) {
    vector <string> ans;
    int n = words.size();
    if(n==1) return {};
    string it=words[0];
    for(int i=0;i<n;i++){
        it=_compare(it,words[i]);
    }
    for(auto &x:it){
        string y="";
        y+=x;
        ans.push_back(y);
    }
    return ans;
}
};
