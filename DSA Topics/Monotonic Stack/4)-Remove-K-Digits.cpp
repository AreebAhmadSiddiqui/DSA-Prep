class Solution {
public:          4 
        3       /
       / \     /
      2   2   /
     /     \ /
    1       1

    Koi muhse kahe ki k=1 hai to kya delete karoge to min answer aega

    4 ki 3 3 ko karoge tab aega na kam isliye msb is important

    k= 2 hua to 3 ko remove karo aur fir 2 ko 
    // the whole crux is in this statement : "remove the first "peak" digits"
    // Just remove the peak elements to bring the graph as low as possible
    // Removing from left handside(MSB) is important as it holds the most weightage in our number
    string removeKdigits(string num, int k) {
        
        stack<char> st;
        st.push(num[0]);
        for(int i=1;i<num.size();i++){
            
            while(!st.empty() && st.top()>num[i] && k>0){
                st.pop();
                k--;
            }
            
            // [1,2,0,2,0,0] ka case  2 aur 1 ko pop kar dega fir 0 daldega aagar neche wali line na likhi to
            if(st.empty() && num[i]=='0') continue; // dont push otherwise it will be leading zero
            st.push(num[i]);
        }
        
        // [1,2]  k=2 ka case 
        // If k bach gaya hai to pop k elements
        while(k!=0 && !st.empty()){
            st.pop();
            k--;
        }
        int n=num.size();
        while(!st.empty()){
            num[--n]=st.top();
            st.pop();
        }
        
        return num.substr(n)=="" ? "0" : num.substr(n);
    }
};