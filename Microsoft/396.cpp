class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        
        int ans = 0,sum = 0,res=INT_MIN,x=0;
        
        for(int i=0;i<nums.size();i++)
        {
            ans = ans + i*nums[i];
            sum = sum + nums[i];
        }
        
        res = ans;
        
        for(int i = nums.size()-1;i>0;i--)
        {
            ans = ans + sum - nums[i]*nums.size();
            res = max(res,ans);
        }
        
        return res;
    }
};
