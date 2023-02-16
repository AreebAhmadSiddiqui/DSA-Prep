#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<long long> vll;


// Simply cnt the elements uptill now and check if their frequence is one and cnt==k means these many unique elements
bool containsNoRepeated(vi &cntArray,int k){
	int cnt=0;
	for(int i=0;i<26;i++){
		cnt+=cntArray[i]==1;
	}

	return cnt==k;
}
int getKLengthSubstrings(string &s,int k){
	vector<int> cntArray(26,0);

	int i=0;
	int j=0;
	int cnt=0;
	while(j<s.size()){

		// Do stuff
		cntArray[s[j]-'a']++;

		
		if(j-i+1==k){ // window reached
			// Calculate
			if(containsNoRepeated(cntArray,k)){
				cnt++;
			}

			//Shrink window size
			cntArray[s[i]-'a']--;
			i++;
		}
		j++;
	}
	return cnt;
}
int main() {

#ifdef ONLINEJUDGE
	freopen("inputf.in", "r", stdin); //can need to change file . this one for taking input
	freopen("outputf.in", "w", stdout); // this one for output
#endif
	
	int k;
	cin>>k;
	string s;
	cin>>s;


	cout<<getKLengthSubstrings(s,k);
	return 0;
}