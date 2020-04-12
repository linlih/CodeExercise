class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int max_num = *max_element(nums.begin(), nums.end());
        int single = -1;
        int *arr = new int[max_num];
        for (int i = 0; i < max_num; i++)
            arr[i] = 0;
        for (int i = 0; i < nums.size(); i++)
            arr[nums[i]] ++;
        for (int i = 0; i < max_num; i++)
            if (arr[i] == 1)
                single = arr[i];
        return single;
    }
};