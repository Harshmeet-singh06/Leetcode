class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int level = 0;
        for(auto c : s){
            if(c == '(' && level == 0){
                level++;
            }
            else if(c == '(' && level > 0){
                result += c;
                level++;
            }
            else if(c == ')' && level > 1){
                result += c;
                level--;
            }
            else if(c == ')' && level == 1){
                level--;
            }
        }
        return result;
    }
};