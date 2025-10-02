class Solution {
public:
    int minCost(vector<int>& arr) {   //arr ->  [4, 3, 2, 6]
        // Create a min-heap
        priority_queue<int, vector<int>, greater<int>> pq;

        // Push all elements into the heap
       for(int i = 0; i<arr.size();i++)   //!heap created will be [2,3,4,6]
       {
        int val = arr[i];
        pq.push(val);
       }

        int cost = 0;

        // Keep combining until only one element remains okayyy
        while (pq.size() > 1) {
            int first = pq.top(); //2 //4 //6
            pq.pop();

            int second = pq.top(); //3 //5  //9
            pq.pop();

            int sum = first + second; //2+3 //5+9 //15+5+9
            cost += sum;

            // Push the combined rope back into the heap
            pq.push(sum); //![4,6,5] ->[4,5,6] ->[6,9] ->15 ->24
        }

        return cost;
    }
};
