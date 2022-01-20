https://leetcode.com/problems/find-common-characters/

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
