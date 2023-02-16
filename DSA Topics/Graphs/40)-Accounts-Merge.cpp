class DSU{
	vector<int> rank,parent,size;

public:
	DSU(int n){
		rank.resize(n+1,0);
		parent.resize(n+1,0);
		size.resize(n+1,1);

		for(int i=0;i<=n;i++){
			parent[i]=i;
		}
	}

	int findPar(int u){
		if(u==parent[u]){
			return u;
		}
		return parent[u]=findPar(parent[u]);
	}

	void unionByRank(int u,int v){
		u=findPar(u);
		v=findPar(v);

		if(u==v) return;
		// u is chota than v add it to v
		if(rank[u]<rank[v]){
			parent[u]=v;
		}
		else if(rank[u]>rank[v]){
			parent[v]=u;
		}
		else{
			parent[v]=u;
			rank[u]++;
		}
	}

	void unionBySize(int u,int v){
		u=findPar(u);
		v=findPar(v);

		if(u==v) return;
		// u is chota than v add it to v
		if(size[u]<size[v]){
			parent[u]=v;
			size[v]+=size[u];
		}
		else{
			parent[v]=u;
			size[u]+=size[v];	
		}
	}
};
class Solution {
public:
    STEPS


    a) Sabse pehle to ye kaafi tricky hai soochna lekin ye raha is ka solution
    b) Man ke chalo ki jo accounts diya hai wo index wise node hai pehle account is node 0 doosra node 1 aise hi...
    c) Sabse pehle to map mein emails dalo with key-> email aur value-> index jahan pe wo hai matlab (jis index pe hai wo account ke)
    d) Jab tum dal rahe hoge to dekhna ki kahin wo already to ni present hai map mein agar hai to iska matlab hai ki ye same email hai aur inhe merge karna hai ek main to unionByRank karke merge kardo
    e) aisa sare emails ke saath karo
    f) ab baari baari map mein traverse karo aur find karo email ka ultimate index jo map mein pada hai wo ni ultimate wala

    kyun? dekho

    [[areeb,"a@com","c@com","b@com"],
    [areeb,"d@com","e@com","a@com"]]

    yahan d@com ke lye map mein d@com-> 1 jaega e@com-> 1 jaega lekin a@com already presnt to ham 1 ko 0 se join kar denge
    lekin jab tum map mep iterate karoge to d@com mein to 1 bata raha lekin tum to use kahin aur join kar diye ho isliye ultimate parent nikalna aur us wale index mein dal dena

    g) ye sab emails ko dalne ke liye ek vector<string> emailList[accounts.size()] bana lena aur usmein add kardena
    h) ab tumhe final answer batana hai to iterate karna emailList mein aur dekhna kahin koi index empty to ni hai kyunki empty hua iska matlab ki wahan koi email ni bacha wo already kahin aur update ho chucka hai ex main 1 index jo upar hai wo 0 main chala gaya to maillist[1] empty hogi
    to empty wale ko na dalna aur agar empty ni hai t sort kardena name dalna aur sorted wali list dal dena


    //TC-> O(n*m*4*alpha*logm)
    // SC->(n*m+n*m)
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n=accounts.size();
        unordered_map<string,int> mp; // for storing the email and the index of the name of account; {email,index}
        
        DSU ds(n);
        
        // O(n*m*1*4*alpha) ~ O(n*m)
        for(int i=0;i<n;i++){
            // O(m*1*4*alpha)
            for(int j=1;j<accounts[i].size();j++){ // leave first element as it is the name of account
                string email=accounts[i][j];
                
                if(mp.find(email)!=mp.end()){ // it means same email is already present so connect this to my ultimate parent
                    
                    int u=mp[email];
                    int v=i;
                    ds.unionByRank(u,v);
                }
                else{
                    mp[email]=i; // store the index so as to provide easy access
                }
            }
        }
        
        // Our DSU is created Now We need to merge
        
        vector<string> emailList[n];
        
        // O(n*m*4*alpha)
        for(auto &it:mp){
            
            string email=it.first;
            int index=it.second;
            
            int ultimateParentIndex=ds.findPar(index); // ham seedhe index ko ni use kar skate ultimate parent nikalo aur usmein add karo
            emailList[ultimateParentIndex].push_back(email);
        }
        
        vector<vector<string>> ans;
        
        // O(n*m*4*alpha*logm)
        for(int i=0;i<n;i++){
            if(emailList[i].size()!=0){ // koi to hai waha empty ni hai ; empty matlab sab email merge ho gaye ksii mein
                vector<string> temp;
                
                temp.push_back(accounts[i][0]); // name
                
                sort(emailList[i].begin(),emailList[i].end());
                
                for(auto mail:emailList[i])
                    temp.push_back(mail);
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};