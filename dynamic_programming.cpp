class Solution {
public:
    int split[1001][1001], dp[1001];
    int solve(vector<int> &nums, int k, int idx)
    {
        if(idx>=nums.size())
            return 0;

        if(dp[idx]!=-1)
            return dp[idx];

        int score=INT_MAX;

        for(int i=idx; i<nums.size(); i++)
        {
            int curr= k+ split[idx][i] + solve(nums, k, i+1);
            score= min(score, curr);
        }

        return dp[idx]=score;
    }
    int minCost(vector<int>& nums, int k)
    {
        memset(dp, -1, sizeof(dp));

        for(int i=0; i<nums.size(); i++){
            unordered_map<int,int> s;
            int trim=0;

            for(int j=i; j<nums.size(); j++){
                s[nums[j]]++;

                if(s[nums[j]]==2)
                    trim+=2;
                else if(s[nums[j]]>2) trim++;

                split[i][j]=trim;

            }

        }

        return solve(nums, k, 0);
    }
};
