class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1 && trust.empty()) return 1;
        vector<int> trustedbyCount(n+1, 0);
        for(const auto& relation : trust){
            int row = relation[0];
            int col = relation[1];
            trustedbyCount[row] = -1;
        
        if(trustedbyCount[col] != -1){
            trustedbyCount[col]++;
        }
        }
        for(int i =1; i<=n;i++){
            if(trustedbyCount[i]==n - 1){
                return i;
            }
        }
        return -1;

    }
};