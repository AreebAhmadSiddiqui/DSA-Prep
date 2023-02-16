// Step By Step Approach ki kya kar rahe kyun kar rahe aur kaise kar rahe (what? why? How?)

a) Sabse pehle to sare characters jo ki t mein hai unhe ek map mein store kar lo usse kya fayda hoga ki hame check kar paenge ki jo substring hamne s main li hai uske sare characters t main hai bhi ya ni
b) Aur map ko change karenge ham dekho kya kah raha main 

mp[char] ki teen values ho sakti hai 

mp[char] > 0 -> Iska matlab hai ki hamare substring mein ye wala char aur hona chahiye
mp[char] == 0 -> Iska matlab hai ki hamare substring mein ye wala char exact amount mein ho gaya hai ( Aur jaise hi ye hoe to cnt ko bhada dena kyunki usse ye pata chalega ki is char jitni baar bhi chahiye tha mere substring mein hai. (Basically cnt ko bhadane ka faayda ye hoga ki hame sirf jo map ka size hai ussi se check karna padega warna map ke size se check karo aur fir unmein jitne element hai wo bhi barabar ho to O(n2) ho jaega)
mp[char] < 0 -> Iska matlab hai ki hamare substring mein ye wala char excess mein hai to jab ham apni window ko chota karenge to ye wale elements ko hataya ja sakta hai kyunki jitna -ve hai uska matlab utne extra characters


c) Jaise hi cnt==mp.size() ho iska matlab hame ek probable substring mil gayi hai to use ans mein store kar lo ya startIndex aur len store kar lo baar baar substr chalane bhi time consuming hoga

d) Ab dekho sabse important part hame window ko decrease karna hai okk

to decrease kab tak karoge jab tak jo s[i] wala banda hai wo 0 ke equal na ho jae yahi to tha ki s[i]<0 jitna hoga utne extra characters hai to unhe hata sakte ho to hata do

e) hatane ke baad bhi check karna padega jo min window ai do contions lag rahi ti agar aisa ni karna to seedhe ek hi main dal do (Are tum do baar answer mein store kar rahe the na isliye wo wali line ko neeche dal do is check ke to ek baar hi check karna padega)

class Solution {
public:
    string minWindow(string s, string t) {
     
        unordered_map<int,int> mp;
        
        // O(n)
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
        }
        int i=0;
        int j=0;
        int cnt=0; // for counting whther all our charaters are added in our substring
        
        int mini=INT_MAX;
        int startIndex=0;
        int size=mp.size(); // This is the number of unique characters in t
        
        // O(m+m)
        while(j<s.size()){
            
            // Do stuff
            mp[s[j]]--;
            
            if(mp[s[j]]==0){ // 0 signify that we have included all characters of s[j]
                cnt++; 
            }
            
            if(cnt==size){ // it means sare characters a gae mere substring mein
                

                // Ye do condition ki baat kar rha ek yaha likho hai aur ek neeche to dono ko nechec hi le jao
                // if(j-i+1<mini){
                //     mini=j-i+1;
                //     startIndex=i;
                // }
                // See if we can shrink our window
                while(mp[s[i]]!=0){
                    mp[s[i]]++;
                    i++;
                }
                
                if(j-i+1<mini){
                    mini=j-i+1;
                    startIndex=i;
                }
            }
            j++;
        }
        
        return mini==INT_MAX ? "" : s.substr(startIndex,mini);
    }
};