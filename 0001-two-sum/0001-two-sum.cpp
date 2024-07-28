class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	       map<int,int> mpp;
            int length=nums.size();
        for(int i=0;i<length;i++)
        {
            int num =nums[i];
            int targetno = target - num;
            if(mpp.find(targetno) != mpp.end())
            {
                return{mpp[targetno],i};
            }   
            mpp[num]=i;
        } 
        return {-1,-1}; 
	}
};