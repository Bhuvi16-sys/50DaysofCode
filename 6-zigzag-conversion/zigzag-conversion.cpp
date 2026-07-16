class Solution {
public:
    string convert(string s, int numRows) {
        //base case
        if(numRows ==1 || numRows >= s.length()){
            return s;
        }
        //create a vector of string to hold characters
        vector<string> rows(min(numRows, int(s.length())));
        int row = 0;
        bool goingDown = false;
        for (char c : s){
            rows[row] += c;
        
        if(row == 0 || row == numRows - 1){
            goingDown  =! goingDown;
        }
        row += goingDown ? 1 : -1;
        }
        string result;
        for(string r: rows){
            result += r;
        }
        return result;
    }
};