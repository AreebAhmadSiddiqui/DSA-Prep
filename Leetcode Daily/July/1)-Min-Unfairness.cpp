2305. Fair Distribution of Cookies

You are given an integer array cookies, where cookies[i] denotes the number of cookies in the ith bag. You are also given an integer k that denotes the number of children to distribute all the bags of cookies to. All the cookies in the same bag must go to the same child and cannot be split up.

The unfairness of a distribution is defined as the maximum total cookies obtained by a single child in the distribution.

Return the minimum unfairness of all distributions.
    
    
class Solution {
private:
    void help(int i,int n,vector<int> &cookies,vector<int> &childrenSum,int k,int &ans){
        if(i==n){
            int maxi=0;
            for(auto &it:childrenSum) maxi=max(maxi,it);
            ans=min(ans,maxi);
            return;
        }
        
        for(int child=0;child<k;child++){
            childrenSum[child]+=cookies[i];
            help(i+1,n,cookies,childrenSum,k,ans);
            childrenSum[child]-=cookies[i];
        }
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        
        vector<int> childrenSum(k,0);
        
        int ans=1e9;
        help(0,cookies.size(),cookies,childrenSum,k,ans);
        
        return ans;
    }
};