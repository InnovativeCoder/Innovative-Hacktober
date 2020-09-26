/*This is a function problem.You only need to complete the function given below*/
/*  Structure of a Binary Tree 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
/* Function to get the maximum width of a binary tree*/
int getMaxWidth(Node* root)
{
   // Your code here
   if(root==NULL)
   return 0;
   else{
       queue<Node* > q;
       int ans=0;
       q.push(root);
       while(!q.empty())
       {
           int count=q.size();
           ans=max(count, ans);
           while(count--)
           {
              Node* temp= q.front();
              if(temp->left!=NULL)
              q.push(temp->left);
              if(temp->right!=NULL)
              q.push(temp->right);
              q.pop();
           }
       }
       return ans;
       
   }
   
}
