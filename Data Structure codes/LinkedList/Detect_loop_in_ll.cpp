#include<unordered_map>
int detectloop(Node *head) {
    
    // your code here
    unordered_map<Node*,bool> mp;
    Node* temp = head;
    if(temp==NULL)
    return 0 ;
   
    else
    {
         Node* slow_ptr= temp;
         Node* fast_ptr=temp;
        while(slow_ptr!=NULL && fast_ptr!= NULL&& fast_ptr->next!=NULL)
        {
            slow_ptr=slow_ptr->next;
            fast_ptr=fast_ptr->next->next;
            if(slow_ptr==fast_ptr)
            return 1;
        }
        return 0;
    }
    
}
