class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

     unordered_map<int, int> freq;

    // Count frequencies
    for (int num : nums)
    {
        freq[num]++;
    }

    // Buckets indexed by frequency
    vector<vector<int>> bucket(nums.size() + 1);

    for (auto &it : freq)
    {
        int number = it.first;
        int count = it.second;

        bucket[count].push_back(number);
    }

    vector<int> result;

    // Traverse from highest frequency to lowest
    for (int i = nums.size(); i >= 1 && result.size() < k; i--)
    {
        for (int num : bucket[i])
        {
            result.push_back(num);

            if (result.size() == k)
                break;
        }
    }

    return result;
}
};
