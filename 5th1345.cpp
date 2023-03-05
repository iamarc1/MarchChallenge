class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 0;

        unordered_map<int, vector<int>> mp;
        for(int i=0; i<n; i++)
            mp[arr[i]].push_back(i);

        queue<int> q;
        q.push(0);
        int mini=0;

        while(!q.empty()){
            int k = q.size();
            mini++;
            while(k--){
                int idx = q.front();
                
                if(idx+1 < n && mp.find(arr[idx + 1]) != mp.end()){
                    if(idx +1 == n-1)
                        return mini;
                    q.push(idx+1);
                }
                if(idx-1 >= 0 && mp.find(arr[idx - 1]) != mp.end()){
                    q.push(idx-1);
                }

                for(auto it : mp[arr[idx]]){
                    if(it == idx || it == idx+1 || it == idx-1)
                        continue;
                    if(it == n-1)
                        return mini;
                    q.push(it);
                }
                mp.erase(arr[idx]);
                q.pop();
            }
        }
        return mini;
    }
};
