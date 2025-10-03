class compare
{
    public:
    bool operator()(ListNode*a , ListNode*b)
    {
        return a->val > b->val;
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*> , compare>pq;

        ListNode* head = NULL;
        ListNode* tail = NULL;

        int totalRows = lists.size();

        //process the first k elements
        for(int row = 0; row<totalRows; row++)
        {
           ListNode* temp  = lists[row];
           if(temp!=NULL){
            pq.push(temp);
           }
        }

        //main logic
        while(!pq.empty())
        {
            //front nikalo
            ListNode* front = pq.top();
            pq.pop();
            
            //inserting the first node
            if(head == NULL && tail ==NULL)
            {
                head = front;
                tail = front;
            }
            else
            {
                tail->next = front;
                tail = front;
            }

            if(tail->next!=NULL)
            {
                pq.push(tail->next);
            }
        }
        return head;
        
    }
};