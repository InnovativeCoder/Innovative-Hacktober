Node *removeDuplicates(Node *root)
{
 // your code goes here
 unordered_map<int, bool>  mp;
 Node* temp=root;
 if(temp==NULL)
 return temp;
 else
 {
     Node* prev=root;
     Node* curr= root;
     while(curr!=NULL)
     {
         if(mp[curr->data])
         {
             //cout<<"if"<<curr->data;
             Node* free_node= curr;
             prev->next=curr->next;
             free(free_node);
         }
         else
         {
           //cout<<"else"<<curr->data;
             mp[curr->data]=true;
             prev=curr;
         }
         curr=prev->next;
         
     }
     return temp;
 }
}