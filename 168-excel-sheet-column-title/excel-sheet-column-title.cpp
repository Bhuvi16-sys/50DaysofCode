class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while(columnNumber>0){
            columnNumber--;
            char rem = 'A' + (columnNumber % 26);
            result += rem;
            columnNumber /= 26;

        }
        reverse(result.begin(), result.end());
        return result;
    }
};