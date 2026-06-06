class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> v;
       
        for(int i =0; i < nums.size(); i++)
        {   
             int num = 1;
           for(int j =0; j < nums.size(); j ++)
           {
                if(i != j)
                    num = num * nums[j];
           }

           v.push_back(num);
        }

    return v;
    }
};
