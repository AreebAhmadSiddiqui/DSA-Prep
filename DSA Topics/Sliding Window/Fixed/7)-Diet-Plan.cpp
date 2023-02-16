A dieter consumes calories[i] calories on the i-th day.

Given an integer k, for every consecutive sequence of k days (calories[i], calories[i+1], ..., calories[i+k-1] for all 0 <= i <= n-k), they look at T, the total calories consumed during that sequence of k days (calories[i] + calories[i+1] + ... + calories[i+k-1]):

If T < lower, they performed poorly on their diet and lose 1 point;
If T > upper, they performed well on their diet and gain 1 point;
Otherwise, they performed normally and there is no change in points.
Initially, the dieter has zero points. Return the total number of points the dieter has after dieting for calories.length days.

Note that the total points can be negative.

int getDietPlanPerformance(vi &calories,int k,int lower,int upper){

	int points=0;
	int i=0;
	int j=0;
	int caloriesSum=0;
	while(j<calories.size()){

		// Do stuff
		caloriesSum+=calories[j];

		if(j-i+1==k){ // Reached window end

			// Calculate
			if(caloriesSum<lower) points--;
			else if(caloriesSum>upper) points++;

			// Shrink window
			caloriesSum-=calories[i];
			i++;
		}
		j++;
	}

	return points;
}
int main() {

#ifdef ONLINEJUDGE
	freopen("inputf.in", "r", stdin); //can need to change file . this one for taking input
	freopen("outputf.in", "w", stdout); // this one for output
#endif
	
	int n,k,l,u;
	cin>>n>>k>>l>>u;

	vector<int> calories(n,0);
	for(int i=0;i<n;i++) cin>>calories[i];

	cout<<getDietPlanPerformance(calories,k,l,u);
	return 0;
}