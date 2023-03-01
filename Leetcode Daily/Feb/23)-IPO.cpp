IPO

Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.

You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.

Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.

Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.

The answer is guaranteed to fit in a 32-bit signed integer.
    

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        vector<pair<int,int>> data;
        for(int i=0;i<profits.size();i++){
            data.push_back({capital[i],profits[i]});
        }
        
        // Sort according to capital
        // Because agar sort ni karenge to baar baar loop karna padega aur n2 complexity ho jaegi
        // Sort karne ka ye bhi fayda hai ki agar ith capital currCapital se chota hai to skip kardo aur fir kabhi uspe wapis ni ana hai so age badhte raho
        
        sort(data.begin(),data.end());
        
        // priority queue bhi banaenge
        // Isse har currCapital pe max value mil jaegi
        
        priority_queue<int> pq;
        
        int currCapital=w;
        int i=0;
        // K distinct objects lene hai
        while(k--){
            
            while(i<profits.size() && data[i].first<=currCapital){
                pq.push(data[i].second);
                i++;
            }
            
            // currCapital kisi bhi capital se bada na ho to pq mein kuch aega ni aur wo age bhi ni ja paega so break kar jao
            if(pq.empty()) break;
            
            // Get the max profit for this capital
            int maxProfit=pq.top();
            // capital mein uska profit jod do
            currCapital+=maxProfit;
            pq.pop();
        }
        
        return currCapital;
    }
};