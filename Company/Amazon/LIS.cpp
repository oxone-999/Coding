//DP solution

int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[n+1];
        
        dp[0] = 1;
        
        int mx = INT_MIN;
        for(int i=0;i<n;i++)
        {
            dp[i] = 1;
            for(int j=0;j<i;j++)
            {
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i],dp[j]+1);   
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            mx = max(mx,dp[i]);
        }
        
        return mx;
    }

//Binary Solution

int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec;
        
        for(int i=0;i<n;i++)
        {
            if(!vec.empty() && vec.back() >= nums[i]){
                int ind = lower_bound(vec.begin(),vec.end(),nums[i]) - vec.begin();
            
                if(ind + vec.begin() !=  vec.end())
                {
                    vec[ind] = nums[i];
                }    
            }
            else vec.push_back(nums[i]);
        }
        
        return vec.size();
    }