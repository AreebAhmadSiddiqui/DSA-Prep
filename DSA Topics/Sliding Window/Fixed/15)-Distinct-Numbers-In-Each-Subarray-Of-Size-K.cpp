Distinct Numbers in Each Subarray

Given an integer array nums and an integer k, you are asked to construct the array ans of size n-k+1 where ans[i] is the number of distinct numbers in the subarray nums[i:i+k-1] = [nums[i], nums[i+1], ..., nums[i+k-1]].

Return the array ans.

int main() {

#ifdef ONLINEJUDGE
	freopen("inputf.in", "r", stdin); //can need to change file . this one for taking input
	freopen("outputf.in", "w", stdout); // this one for output
#endif

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;

		vi nums(n, 0);

		for (int i = 0; i < n; i++) cin >> nums[i];

		int i = 0;
		int j = 0;
		unordered_map<int, int> mp;
		vector<int> ans;
		while (j < n) {

			// Do stuff
			mp[nums[j]]++;

			if (j - i + 1 == k) { // window reached
				ans.push_back(mp.size());

				// Shrink the window
				if (mp[nums[i]] == 1) mp.erase(nums[i]);
				else mp[nums[i]]--;

				i++;
			}
			j++;
		}

		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << '\n';
	}
	return 0;
}