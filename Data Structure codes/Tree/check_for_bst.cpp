/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
}; */
bool bstu(Node* node, int min,int max)
{
    if(node==NULL)
    return true;
    
    if(node->data>max || node->data<min)
    return false;
    
    return bstu(node->left, min, node->data-1) && bstu(node->right, node->data+1, max);
}
bool isBST(Node* root) {
    // Your code here
    bstu(root, INT_MIN, INT_MAX);
   
}
