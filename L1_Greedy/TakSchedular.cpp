int leastInterval(vector<char>& tasks, int n) {
    int f[26]={0};
    for(int i =0;i<tasks.size();i++){
        f[tasks[i]-'A']++;
    }
    sort(f,f+26);
    int chunks = f[25]-1;
    int idlespot = chunks*n;

    for(int i = 24;i>=0;i--){
        idlespot-=min(chunks,f[i]);
    }
    return idlespot<0 ? tasks.size(): tasks.size()+idlespot;
}