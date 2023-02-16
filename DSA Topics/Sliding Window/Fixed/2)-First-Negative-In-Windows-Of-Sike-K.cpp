vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    
    deque<long long int> dq;
    vector<long long> ans;                  
    
    int i=0;
    int j=0;
    while(j<N){
        
        // Agar negative hai tab dq mein rakh lo
        if(A[j]<0){
            dq.push_back(j);
        }

        // jaise hi window size hit karo check karo
        if(j-i+1==K){
            
            if(!dq.empty()){ // pehla banda would be the min element
                ans.push_back(A[dq.front()]);
            }
            else{ // matlab sare positive the is window main
                ans.push_back(0);
            }
        
            // But before sliding we need to be check whether the front element of the deque is equal to the element we are gonna rempve
            
            if(!dq.empty() && dq.front()==i){ // remove it
                dq.pop_front();
            }
             // Now we need to slide our window
            i++;
        }
        j++;
    }
    return ans;
 }