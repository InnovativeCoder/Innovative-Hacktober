/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */

public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) 
    {
       int a=len(headA);
        int b=len(headB);
        int c;
        if(a<b){
            c=b-a;
            while(c>0){
                headB=headB.next;
                c--;
            }
        }
        else{
            c=a-b;
             while(c>0){
                headA=headA.next;
                 c--;
            }
        }
        
        while(headA!=headB && headA!=null){
            headA=headA.next;
            headB=headB.next;
        }
        return headA;       
    }
   
    public int len(ListNode head){
        int a=0;
        while(head!=null){
            a++;
            head=head.next;
        }
        return a;
    }
    
}
