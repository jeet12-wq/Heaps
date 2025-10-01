class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        //i created a min. heap
        priority_queue<int,vector<int>,greater<int>>pq;
        
        //given k elemnts ko push krdia pehle pq mai
        for(int i = 0;i<k;i++)
        {
            pq.push(nums[i]);
        }
        
        //remaining elements ko process kia and check kia 
        //ki jo element aage ka hai wo > pq.top(){jisme smallest element hoga } if true then     pop and push    
        for(int i = k;i<nums.size();i++)
        {
            int element = nums[i];

            if(element>pq.top())
            {
                pq.pop();
                pq.push(element);
            }
        }
        int ans  = pq.top();
        return ans;
        
    }
};