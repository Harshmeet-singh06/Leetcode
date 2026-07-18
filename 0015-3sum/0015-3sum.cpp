class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        int n = a.size();
        sort(a.begin(),a.end());
        vector<vector<int>> ans;
        if(n == 0){
            return ans;
        }
        for(int i=0;i<n;i++){
            if(i > 0 && a[i] == a[i-1]){
                continue;
            }
            int j = i + 1;
            int k = n - 1;
            vector<int> temp;
            while(j < k){
                int sum = a[i] + a[j] + a[k];
                if(sum < 0){
                    j++;
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    temp = {a[i],a[j],a[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j < k && a[j-1] == a[j]){
                        j++;
                    }
                    while(j < k && a[k+1] == a[k]){
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};