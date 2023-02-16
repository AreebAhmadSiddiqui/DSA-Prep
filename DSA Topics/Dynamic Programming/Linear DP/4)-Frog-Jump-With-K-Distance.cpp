#include<bits/stdc++.h>
using namespace std;
int help(int i, vector<int> &heights, vector<int> &dp, int k) {
	if (i == 0) return 0;

	if (dp[i] != -1) return dp[i];

	int jump = INT_MAX;
	for (int j = 1; j <= k; j++) {
		if (i - j >= 0) jump = min(jump, abs(heights[i - j] - heights[i]) + help(i - j, heights, dp, k));
	}

	return dp[i] = jump;
}
void tabulation(int n, vector<int> &heights, int k) {

	vector<int> dp(n, 0);

	dp[0] = 0;

	for (int i = 1; i < n; i++) {
		int jump = INT_MAX;
		for (int j = 1; j <= k; j++) {
			if (i - j >= 0) jump = min(jump, abs(heights[i - j] - heights[i]) + dp[i - j]);
		}
		dp[i] = jump;
	}

	cout<<dp[n-1];
}

int main() {

	int n, k;
	cin >> n >> k;

	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> dp(n, -1);
	cout << help(n - 1, arr, dp, k);
	tabulation(n, arr,  k);
}

