// Algorithm

a) Brute to hoga ki har i ke liye circular traverse karo aur dekho pahunch pa rahe ki ni 
b) Optimal hai jo maine likha hai lekin ye code to bahut assan hai samjhne mein band baj gayi thi

-> Yahan ek observation hai wo dekho ki agar main kisi station A se doosre station B ni pahunch sakta to A aur B ke beech ke kisi station se bhi ni pahunchunga

proof

Facts: 
i) A cannot reach B
ii) A and B have C1,c2,c3,..ck station in between
iii) A can reach C1,c2,c2,c3,ck (are ismein doubt hai to noob ho tum agar yahi ni pahunch paya to b kya pahunchega noob)

Assume C1 can reach B (agar ise prove kar diya to observation galat)

C1 -> B (Given)
A -> C1 (Fact 3)
-------
A -> B (Contradiction) is liye prove ho gaya ki koi bhi station a aur b ke beechi mein b ni pahunchega to seedhe b se age se check karo iteration a aur b ke beech walon ki zarurat ni


c) Tum ye bhi kah sakte ho chalo ye prove ho gaya to ham ek paas mein kar sakte kuch lekin agar ith index pe khade hai aur ith index pe dobar pahunchna hai to loop lagane padega na
d) uske liye precompute kar ke rakho ki start se pehle tak kitna fuel chahiye/ ya consume hoga agar 0 se i tak ae 
e) dekho ye confirm hai ki answer agar hoga to ek hi hoga multiple ni honge to jahan bhi answer hoga wahan se shuru karenge to wo end tak jaega
f) Isliye har baar totalFuel ko bhadate jao agar kisi bhi point pe totalFuel < 0 ho gaya iska matlab start -> i ni aya ja sakta to start -> i+1 kar do
g) aur abhi tak jitna fuel consume hua hai use totalFuelConsumed mein add kardo ye baad mein kaam aega prefix array jaise
h) aur agar maanlo lo tum array ke last mein pahunch gae matlab loop ke bahar a gae
i) to check karo ki tumhare pass jo fuel hai gadi main totalfuel wo minus jitna start tak pahunche ki liye chahiye wo greater > = 0 hai ki n agar hai to start index return kar do warna seedhe seedhe kah do ki ni pahunch sakte
j) ek baat aur soch rahe hoge ki totalFuel+totalFuelConsumed ye kyun kar raha minus karna tha na , are wo minus mein hi to answer aega to agar minus likhunga to add ho jaega isliye

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int totalFuel=0;
        int startIndex=0;
        int totalFuelConsumed=0; // Going 0 to i kind of a prefix array
        for(int i=0;i<gas.size();i++){
            totalFuel+=gas[i]-cost[i];
            
            // We need to change our start
            if(totalFuel<0){
                startIndex=i+1;

                // abhi tak ka fuel ko store kar lo
                totalFuelConsumed+=totalFuel;
                totalFuel=0;
            }
        }
        return totalFuel+totalFuelConsumed>= 0 ? startIndex : -1;
    }
};