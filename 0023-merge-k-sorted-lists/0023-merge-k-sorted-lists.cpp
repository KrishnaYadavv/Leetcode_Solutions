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

ListNode* lans = NULL;

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode(-1);
        ListNode* ans = temp;

        while (l1 != NULL || l2 != NULL) {
            if (l1 == NULL) {
                temp->next = l2;
                return ans->next;
            }
            if (l2 == NULL) {
                temp->next = l1;
                return ans->next;
            }
            if(l1->val>l2->val){
                temp->next=l2;
                l2=l2->next;
                temp=temp->next;
            }
            else{
                temp->next=l1;
                l1=l1->next;
                temp=temp->next;
            }
        }
        lans=ans->next;
        return ans->next;
    }

    ListNode* solve(vector<ListNode*>& lists,int i){
    if(i==lists.size()){
        return NULL;
    }

    ListNode* rest = solve(lists,i+1);
    return merge(lists[i], rest);
}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return solve (lists,0);
    }
};