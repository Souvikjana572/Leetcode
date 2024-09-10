/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode*node=head;
        while(node->next){
            ListNode*temp=new ListNode();
            temp->val=__gcd(node->val,node->next->val);
            temp->next=node->next;
            node->next=temp;
            node=temp->next;
        }
        return head;
    }
};
