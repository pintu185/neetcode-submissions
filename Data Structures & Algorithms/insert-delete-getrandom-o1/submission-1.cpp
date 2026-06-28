class RandomizedSet {
    private: 
        unordered_map<int, int> persent;
        vector<int> nums;
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(persent.find(val) != persent.end())
            return false;
        persent[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(persent.find(val) == persent.end())
            return false;
        int lastElement = nums.back();
        int idxToRemove = persent[val];
        nums[idxToRemove] = lastElement;
        persent[lastElement] = idxToRemove;
        nums.pop_back();
        persent.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};
