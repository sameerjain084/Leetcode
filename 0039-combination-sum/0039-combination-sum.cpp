class Solution {
public:
    void getAllCombinations(vector<int>& arr, int idx, int target,
                            vector<vector<int>>& ans,
                            vector<int>& combin) {

        // Base Case: Target achieved
        if (target == 0) {
            ans.push_back(combin);
            return;
        }

        // Base Case: Out of bounds or target becomes negative
        if (idx == arr.size() || target < 0) {
            return;
        }

        // Choice 1: Include current element
        combin.push_back(arr[idx]);
        getAllCombinations(arr, idx, target - arr[idx], ans, combin);
        combin.pop_back();

        // Choice 2: Exclude current element
        getAllCombinations(arr, idx + 1, target, ans, combin);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> combin;

        getAllCombinations(arr, 0, target, ans, combin);

        return ans;
    }
};