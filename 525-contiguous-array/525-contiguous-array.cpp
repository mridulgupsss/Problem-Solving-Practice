class Solution {
public:
    int findMaxLength(vector<int>& nums) {
            int sum=0;
        int len=0;
        unordered_map<int, int> mp;
        mp[0]=-1;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==1)
            {
                sum+=1;
            }
            else
            {
                sum+=-1;
            }
            if(mp.find(sum)!=mp.end())
            {
                if(len<i-mp[sum])
                {
                    len=i-mp[sum];
                }
            }
            else
            {
                mp[sum]= i;
            }
                
        }
        return len;
    }
};