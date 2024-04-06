
    return false;
}
Node* build(Node* root){
    cout<<"enter data";
    int d; cin>>d;
    if(d==-1) return NULL;
    root = new Node(d);