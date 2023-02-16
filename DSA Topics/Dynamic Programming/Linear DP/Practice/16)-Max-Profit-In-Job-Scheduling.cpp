// Steps

a) Pehle to sort kar do start time ke basis pe kyunki agar sort kar doge to prev i ki zarurat ni padegi warna n2 ho jaega
b) ab tum is bande ko pick kar sakte ho ya to ni to do case bane pick and not pick wale 
c) tumne pick kiya agar ise to tumhe agla index jiska start time curr end time se bada ho wo chahiye lekin agar normal loop lagaya to n2 ho jaega
d) sorted hai bhai to BS laga do i+1,size tak jo index mile use le lo
e) ya fir na pick karo 
f) max le lo ant main
struct Data{
    int s,e,p;
    Data(int start,int end,int pro){
        s=start;
        e=end;
        p=pro;
    }
};
class Solution {
private:
    static bool comp(Data &a,Data &b){ // Sort according to start time
        return a.s<b.s;
    }
public:
    int help(int i,vector<Data> &jobs,vector<int> &dp){
        if(i==jobs.size()) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        int nextJobIndex=getNextJob(i,jobs[i].e, jobs); // {first job whose start time >=ending time of this job}
        int pick=jobs[i].p+help(nextJobIndex,jobs,dp);
        int notPick=0+help(i+1,jobs,dp);
        
        return dp[i]=max(pick,notPick);
    }
    int tabulation(vector<int>& startTime, vector<int>& endTime, vector<int>& profit){
        vector<Data> jobs;
        for(int i=0;i<startTime.size();i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        
        sort(jobs.begin(),jobs.end(),comp);
        
        vector<int> dp(jobs.size()+1,0);
        
        // Base Case
        dp[jobs.size()]=0;
        
        
        for(int i=jobs.size()-1;i>=0;i--){
            int nextJobIndex=getNextJob(i+1,jobs[i].e, jobs); // {first job whose start time >=ending time of this job}
            int pick=jobs[i].p+dp[nextJobIndex];
            int notPick=0+dp[i+1];

            dp[i]=max(pick,notPick);
        }
        
        return dp[0];
    }
    int getNextJob(int start,int target,vector<Data> &jobs){
        
        int end=jobs.size()-1;
        int ans=jobs.size();
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(jobs[mid].s>=target){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
//         vector<Data> jobs;
//         for(int i=0;i<startTime.size();i++){
//             jobs.push_back({startTime[i],endTime[i],profit[i]});
//         }
        
//         sort(jobs.begin(),jobs.end(),comp);
        
//         vector<int> dp(jobs.size()+1,-1);
//         return help(0,jobs,dp);
        return tabulation(startTime,endTime,profit);
    }
};