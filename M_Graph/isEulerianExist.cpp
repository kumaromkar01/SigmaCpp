// https://www.geeksforgeeks.org/problems/euler-circuit-in-a-directed-graph/1


bool isEularCircuitExist(int v, vector<int>adj[]){
	    // Code here
	    vector<int> deg(v);
	    for(int i=0;i<v;i++){
	        deg[i]=adj[i].size();
	    }
	    int cnt=0;
	    for(int i=0;i<v;i++){
	        if(deg[i]%2!=0) cnt++;
	    }
	    //if a graph has 0 vertices of odd degree then exists eulerian ckt
	    return cnt==0?true: false;
	}
        //NOTE : 
        //if a graph has more than two vertices of odd degree then no euler path.
        //if a graph is connected and it has exactly 0 or 2 vertices of odd degree
        // then there exist atleast one eulerian path.