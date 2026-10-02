class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        int l = 0;
        int r = n-1;
        int total = 0;
        int left = 0;
        int right = 0;
        while(l <= r){
            if(a[l] <= a[r]){
                if(a[l] <= left){
                    total += left - a[l];
                }
                else{
                    left = a[l];
                }
                l++;
            }
            else{
                if(a[r] <= right){
                    total += right - a[r];
                }
                else{
                    right = a[r];
                }
                r--;
            }
        }
        return total;
    }
};