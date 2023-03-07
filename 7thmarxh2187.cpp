class Solution {
public:
    long long numberOfTripsForGivenTime(vector<int>&a , long long int givenTime)
    {
        long long totalTrips = 0;
        for(auto x : a)
        {
            long long val = x;	
            totalTrips += (givenTime / val);
        }
        return totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long lowestTime = 1;
        long long highestTime = 1e14;
        while(lowestTime<highestTime)
        {
            long long mid = lowestTime + (highestTime-lowestTime)/2;
            
            if(numberOfTripsForGivenTime(time , mid) >= totalTrips)
                highestTime = mid;
            else
                lowestTime = mid+1;
        }
        return lowestTime;
    }
};
