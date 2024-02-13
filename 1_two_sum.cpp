#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> result(2, -1);
        unordered_map<int, int> hashMap;

        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            auto it = hashMap.find(complement);

            if (it != hashMap.end())
            {
                result[0] = it->second;
                result[1] = i;
                break;
            }

            hashMap[nums[i]] = i;
        }

        return result;
    }
};

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution solution;
    vector<int> result = solution.twoSum(nums, target);

    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
