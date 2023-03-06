class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=(high-low)/2+low;
            int x=arr[mid]-mid;
            cout<<arr[mid]<<" ";
            if(x>k)
            high=mid-1;
            else
            low=mid+1;
        }
        cout<<low<<"\n";
        return k+low;  
    }
};
