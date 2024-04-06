void solve(int idx, string &s, vector<string>&ans,string output){
	        if(idx>=s.size()) {
	            if(output!="")
	                ans.push_back(output);
	            return;
	        }
	        //exclude
	        solve(idx+1,s,ans,output);
	        //include
	        output.push_back(s[idx]);
	        solve(idx+1,s,ans,output);
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
		    solve(0,s,ans,"");
		    sort(ans.begin(),ans.end());
		    return ans;
		}