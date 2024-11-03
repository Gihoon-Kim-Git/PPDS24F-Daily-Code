
//  Definition for a Node.
struct Node {
      int val;
      int numChildren;
      struct Node** children;
 };
 

int max(int a, int b){
    return a >= b ? a : b;
}

int maxDepth(struct Node* root) {
    if(!root) return 0;

    int cnt = 0;
    for(int i=0;i<root->numChildren;i++){
        cnt = max(cnt,maxDepth(root->children[i]));
    }
    return cnt+1;
}