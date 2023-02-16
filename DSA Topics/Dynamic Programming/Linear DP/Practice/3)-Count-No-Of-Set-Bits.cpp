// Ek approach hai ki total cnt kar lo

O(n) loop chalega ye
a) while(n!=0){
    cnt+=n&1;
    n>>=1;
}

// Algorithm

// O(cnt) // bahut optimised hai ye
Best hai use n&(n-1) because ye remove kar dega last set bit

while(n!=0){
    cnt++;
    n&=(n-1);
}

