class Solution {
public:

    maximum number of choclates batani hai with given coins simple sa tha

    ya to sort kar deta lekin usmein tc zyada warna ye wala kiya tha maine
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> qnt(1e5+1,0); // quantity;
        for(int i=0;i<costs.size();i++){
            qnt[costs[i]]++;
        }
        
        int chocolates=0;
        for(int i=0;i<=1e5;i++){
            if(qnt[i]!=0){
                if(qnt[i]*1ll*i<=coins){
                    chocolates+=qnt[i];
                    coins-=qnt[i]*i;
                }
                else{
                    chocolates+=coins/i;
                    coins%=i;
                }
            }
        }
        return chocolates;
    }
};