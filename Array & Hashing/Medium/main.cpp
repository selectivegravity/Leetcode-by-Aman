class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count=0;
        vector <int> m(60,0);
        for(int n:time){
            n%=60;
            if(n==0) count+=m[0]; 
            else count+=m[60-n];
            m[n]++;
        }
        return count;
    }
};
