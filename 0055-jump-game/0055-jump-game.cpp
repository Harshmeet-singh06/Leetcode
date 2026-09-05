class Solution {
public:
    bool canJump(vector<int>& a) {
        int n = a.size();
        if(n == 0 || n == 1){
            return true;
        }
        int farthest = 0;
        for(int i = 0;i<n;i++){
            if(i > farthest){
                return false;
            }
            farthest = max(farthest,a[i] + i);
            if(farthest >= n-1){
                return true;
            }
        }
        return false;
    }
};