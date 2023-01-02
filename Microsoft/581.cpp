class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        vector<int>res;
        
        for(int i=0;i<nums.size();i++)
        {
            res.push_back(nums[i]);
        }
        
        sort(res.begin(),res.end());
        
        int p = 0,q = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(res[i] != nums[i])
            {
                p = i;
                break;
            }
        }
        
        for(int i = nums.size()-1;i>=0;i--)
        {
            if(res[i] != nums[i])
            {
                q = i;
                break;
            }
        }
        
        if(p == 0 && q == 0)
        {
            return 0;
        }
        
        return q-p+1;
    }
};
