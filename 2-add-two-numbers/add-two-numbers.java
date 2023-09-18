/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode t1=l1,t2=l2;
        ListNode res=new ListNode();
        ListNode t3=res;
        int carry=0;
        while(t1!=null && t2!=null)
        {
            int sum=t1.val+t2.val+carry;
            t3.val=sum%10;
            carry=sum/10;
            if(!(t1.next==null && t2.next==null))
            {
                ListNode temp = new ListNode();
                t3.next=temp;
            }

            if(t1.next==null && t2.next==null && carry!=0)
            {
                ListNode temp= new ListNode(carry);
                t3.next=temp;
            }
            t3=t3.next;
            t2=t2.next;
            t1=t1.next;
        }

        while(t1!=null)
        {
            int sum=t1.val+carry;
            t3.val=sum%10;
            carry=sum/10;
            if(!(t1.next==null))
            {
                ListNode temp= new ListNode();
                t3.next=temp;
            }

            if(t1.next==null && carry!=0)
            {
                ListNode temp= new ListNode(carry);
                t3.next=temp;
            }
            t3=t3.next;
            t1=t1.next;
        }

        while(t2!=null)
        {
            int sum=t2.val+carry;
            t3.val=sum%10;
            carry=sum/10;
            if(!(t2.next==null))
            {
                ListNode temp= new ListNode();
                t3.next=temp;
            }


            if(t2.next==null && carry!=0)
            {
                ListNode temp= new ListNode(carry);
                t3.next=temp;
            }
            t3=t3.next;
            t2=t2.next;
        }

        return res;
    }
}