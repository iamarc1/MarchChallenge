class Solution {
public:
    bool fun(int m,vector<int> &vec,int h){
        int ans=0;
        for(int i=0;i<vec.size();i++){
            ans+=(vec[i]/m)+(vec[i]%m==0 ? 0 : 1);
        }
        return ans<=h;
    }
    int minEatingSpeed(vector<int>& piles, int H) {
        long int l=1,r=1000000000;
        while(l<r){
            long mid=l+(r-l)/2;
            if(fun(mid,piles,H)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
    
};
