
#include<iostream>
using namespace std;
int ans = 100000;

class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int data){
        data = data;
        left = right = NULL;
    }
};


void leaf(Node* x, int val){
    
    if(x == NULL)return;
    
    if(!x->left && !x->right){
        ans = min(ans, val);
        return;
    }   
    
    leaf(x->left, val+1);
    leaf(x->right, val+1);
    
}

bool parent(Node* root, Node*x){
    
    if(root == NULL)
        return false;
    
    if(root == x)
        return true;
    
    bool l = parent(root->left, x);
    if(l){
        leaf(root->right, 2);
    }
    
    bool r = parent(root->right, x);
    if(r){
        leaf(root->left, 2);
    }
    
    return false;
    
}


void solve(Node* root, Node*x){
    

    
    leaf(x , 0);
    parent(root, x);
    
    cout<<ans<<endl;
    
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    
    Node *root  = new Node(1); 
    root->left  = new Node(12); 
    root->right = new Node(13); 
  
    root->right->left   = new Node(14); 
    root->right->right  = new Node(15); 
  
    root->right->left->left   = new Node(21); 
    root->right->left->right  = new Node(22); 
    root->right->right->left  = new Node(23); 
    root->right->right->right = new Node(24); 
  
    root->right->left->left->left  = new Node(1); 
    root->right->left->left->right = new Node(2); 
    root->right->left->right->left  = new Node(3); 
    root->right->left->right->right = new Node(4); 
    root->right->right->left->left  = new Node(5); 
    root->right->right->left->right = new Node(6); 
    root->right->right->right->left = new Node(7); 
    root->right->right->right->right = new Node(8); 
  
    Node *x = root->right; 
    
    solve(root,x);
    return 0;
}
