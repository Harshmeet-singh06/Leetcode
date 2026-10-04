class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int mini = 0;
        int maxe = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                mini = mini + 1;
                maxe = maxe + 1;
            }
            else if(s[i] == ')'){
                mini = mini - 1;
                maxe = maxe -1;
            }
            else{
                mini = mini - 1;
                maxe = maxe + 1;
            }
            if(mini < 0){
                mini = 0;
            }
            if(maxe < 0){
                return false;
            }
        }
        return (mini == 0);
    }
};