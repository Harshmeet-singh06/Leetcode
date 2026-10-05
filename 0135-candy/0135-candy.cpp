class Solution {
public:
    int candy(vector<int>& a) {
        int n = a.size();
        int sum = 1;
        int i = 1;
        while(i < n){
            if(a[i] == a[i-1]){
                sum = sum + 1;
                i++;
                continue;
            }
            int peak = 1;
            while(i < n && a[i] > a[i-1]){
                peak++;
                i++;
                sum += peak;
            }
            int down = 1;
            while(i < n && a[i] < a[i-1]){
                sum += down;
                down++;
                i++;
            }
            if(down > peak){
                sum += down - peak;
            }
        }
        return sum;
    }   
};