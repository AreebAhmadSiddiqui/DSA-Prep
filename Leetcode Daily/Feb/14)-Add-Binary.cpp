class Solution {
private:
    void updateSumAndCarry(int rightDigitOfA,int rightDigitOfB,int &carry,string &ans){
        int sum=rightDigitOfA+rightDigitOfB+carry;
        ans+=(sum%2+'0');
        carry=sum/2;
    }
public:
    string addBinary(string a, string b) {
        int carry=0;
        string ans="";
        int i=a.size()-1;
        int j=b.size()-1;
        
        while(i>=0 || j>=0){
            int rightDigitOfA= i>=0 ? a[i]-'0' : 0;
            int rightDigitOfB= j>=0 ? b[j]-'0' : 0;
            updateSumAndCarry(rightDigitOfA,rightDigitOfB,carry,ans);
            i--;
            j--;
        }
        
        if(carry!=0) ans+=(carry+'0');
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};