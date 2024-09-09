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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<vector<int>>ans(m,vector<int>(n,-1));
        int top=0,bottom=m-1,left=0,right=n-1;
        while(top<=bottom&&left<=right&&head){
            int i=left;
            while(i<=right &&head){
                ans[top][i]=head->val;
                head=head->next;
                i++;
            }
            top++;
            i=top;
            while(i<=bottom&&head){
                ans[i][right]=head->val;
                head=head->next;
                i++;
            }
            right--;
            if(top<=bottom && head){
                i=right;
                while(i>=left&&head){
                ans[bottom][i]=head->val;
                head=head->next;
                i--;
                }
                bottom--;
            }
            if(left<=right &&head){
                i=bottom;
                while(i>=top&&head){
                ans[i][left]=head->val;
                head=head->next;
                i--;
            }
            left++;
            }
        }
        return ans;
    }
};
