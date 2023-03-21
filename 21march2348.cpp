class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
         int n=nums.size();
         vector<int> zero(n,0);
         zero[0]=(nums[0]==0)?1:0;
         for(int i=1; i<n; i++){
            
            zero[i]=(nums[i]==0)?zero[i-1]+1:0;
            
         }
         long long ans=0;
         for(auto &i: zero){
             ans+=i;
         }
         return ans;
    }
};
