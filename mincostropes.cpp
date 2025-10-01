class Solution {
public:
    int minCost(vector<int>& arr) {
        // Create a min-heap
        priority_queue<int, vector<int>, greater<int>> pq;

        // Push all elements into the heap
        for (int val : arr) {
            pq.push(val);
        }

        int cost = 0;

        // Keep combining until only one element remains
        while (pq.size() > 1) {
            int first = pq.top(); 
            pq.pop();

            int second = pq.top(); 
            pq.pop();

            int sum = first + second;
            cost += sum;

            // Push the combined rope back into the heap
            pq.push(sum);
        }

        return cost;
    }
};
