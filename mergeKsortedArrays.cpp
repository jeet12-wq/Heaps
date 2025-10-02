class Solution {
  public:
   
   class Info
   {
       public:
       int data;
       int rIndex;
       int cIndex;
       
    
       Info(int x,int y,int z)
       {
           this->data = x;
           this->rIndex = y;
           this->cIndex = z;
       }
   };
   
   class compare
   {
       public:
       bool operator()(Info*a,Info*b)
       {
           return a->data > b->data;
       }
   };
  
    
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        
        priority_queue<Info* ,vector<Info*>,compare>pq;
        
        vector<int>ans;
        
        int totalrows = arr.size();
        int totalcolumns = arr[0].size();
        
        //inially maine daal die apne elements ko priority queue min heap me
        for(int row =0; row<totalrows; row++)
        {
            int element = arr[row][0];
            Info*  temp = new Info(element,row,0);
            pq.push(temp);
            
        }
        
        
        //main logic
        //yeh logic apne vector created ans me daal raha hui
        while(!pq.empty())
        {
            Info *front = pq.top();
            pq.pop();
            
            int frontdata = front->data;
            int front_rIndex = front->rIndex;
            int front_cIndex = front->cIndex;
            
            ans.push_back(front->data);
            
        //aage wale elemenst agar exist krte hai to unke liye add kro
        if(front_cIndex+1 < totalcolumns)
        {
            int element = arr[front_rIndex][front_cIndex+1];
            Info* temp = new Info(element , front_rIndex, front_cIndex+1);
            pq.push(temp);
        }
        
            
            
        }
         return ans;
        
       
        
        
        
        // code here
        
    }
   
};