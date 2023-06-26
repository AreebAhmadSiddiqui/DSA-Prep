2462. Total Cost to Hire K Workers

You are given a 0-indexed integer array costs where costs[i] is the cost of hiring the ith worker.

You are also given two integers k and candidates. We want to hire exactly k workers according to the following rules:

You will run k sessions and hire exactly one worker in each session.
In each hiring session, choose the worker with the lowest cost from either the first candidates workers or the last candidates workers. Break the tie by the smallest index.
For example, if costs = [3,2,7,7,1,2] and candidates = 2, then in the first hiring session, we will choose the 4th worker because they have the lowest cost [3,2,7,7,1,2].
In the second hiring session, we will choose 1st worker because they have the same lowest cost as 4th worker but they have the smallest index [3,2,7,7,2]. Please note that the indexing may be changed in the process.
If there are fewer than candidates workers remaining, choose the worker with the lowest cost among them. Break the tie by the smallest index.
A worker can only be chosen once.
Return the total cost to hire exactly k workers.
    

Approach

a) Kaafi intuitive hai bas edges cases ka dhyan rakhna hai thora
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
//         priority_queue<int,vector<int>,greater<int>> pq1;
//         priority_queue<int,vector<int>,greater<int>> pq2;
        
//         int n=costs.size();
//         int i=0;
//         int j=n-1;
        
//         while(i<candidates){
//             pq1.push(costs[i++]);
//         }
//         while(j>=n-candidates && j>=i){
//             pq2.push(costs[j--]);
//         }
        
//         long long sum=0;
//         while(k--){
            
//             int val1=1e9;
//             int val2=1e9;
//             if(!pq1.empty()){
//                 val1=pq1.top();
//             }
            
//             if(!pq2.empty()){
//                 val2=pq2.top();
//             }
            
//             sum+=min(val1,val2);
            
//             if(val1<=val2){
//                 if(!pq1.empty()) pq1.pop();
                
//                 if(i<=j){
//                     pq1.push(costs[i++]);
//                 }
//             }else{ // if(val1>val2){
//                 if(!pq2.empty()) pq2.pop();
                
//                 if(i<=j){
//                     pq2.push(costs[j--]);
//                 }
//             }
//         }
        
//         return sum;
        
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // {ele,type}
        
        // Type=0 if is is left part and 1 if it is right part
        
        int n=costs.size();
        int i=0;
        int j=n-1;
        
        while(i<candidates){
            pq.push({costs[i++],0});
        }
        while(j>=n-candidates && j>=i){
            pq.push({costs[j--],1});
        }
        
        long long sum=0;
        while(k-- && !pq.empty()){
            
            auto it=pq.top();
            pq.pop();
            int val=it.first;
            int type=it.second;
            
            sum+=val;
            
            if(type==0){
                if(i<=j){
                    pq.push({costs[i++],0});
                }
            }else{ // if(val1>val2){
                
                if(i<=j){
                    pq.push({costs[j--],1});
                }
            }
        }
        
        return sum;
    }
};