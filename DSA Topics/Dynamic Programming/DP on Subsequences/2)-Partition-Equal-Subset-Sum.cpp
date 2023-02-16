class Solution
{
public:
    bool spaceOptimised(vector<int> arr, int sum)
    {
        vector<int> prev(sum + 1, 0), curr(sum + 1, 0);

        // Base case
        if (arr[0] <= sum)
            prev[arr[0]] = 1;

        for (int i = 1; i < arr.size(); i++)
        {
            for (int k = sum; k >= 0; k--)
            {
                bool pick = false;
                if (k - arr[i] >= 0)
                    pick = prev[k - arr[i]];
                bool notPick = prev[k];

                prev[k] = pick || notPick;
            }
        }

        return prev[sum];
    }
    bool canPartition(vector<int> &arr)
    {
        int target = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            target += arr[i];
        }

        return target & 1 ? false : spaceOptimised(arr, target / 2);
    }
};