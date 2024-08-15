class Solution {
public:
    void next_smaller_element(vector<int>& next_smaller,vector<int> heights,int n){
       
        stack<int> stack;
        stack.push(n);
        for(int i = n-1; i>=0; i--){
           
            int x = heights[i];
            if(stack.top()!=n && heights[stack.top()]<x){
                next_smaller[i] = stack.top();
                stack.push(i); 
            }
            else{
                while(stack.top()!=n && heights[stack.top()]>=x){
                    stack.pop();
                }
                next_smaller[i] = stack.top();
                stack.push(i);
            }
        } //for major 

    } //next smaller

      void prev_smaller_element(vector<int>& prev_smaller,vector<int> heights,int n){
       
        stack<int> stack;
        stack.push(-1);
        for(int i = 0; i<n; i++){
           
            int x = heights[i];
            if( stack.top()!=-1 && heights[stack.top()]<x){
                prev_smaller[i] = stack.top();
                stack.push(i); 
            }
            else{
                while(stack.top()!=-1 && heights[stack.top()]>=x){
                    stack.pop();
                }
                prev_smaller[i] = stack.top();
                stack.push(i);
            }
        } // for major 

    } //prev smaller



    int largestRectangleArea(vector<int>& heights) {
        ios_base::sync_with_stdio(0);
         vector<int> next_smaller;
         int n = heights.size();
         next_smaller.reserve(n);
         vector<int> prev_smaller;
         prev_smaller.reserve(n);
         next_smaller_element(next_smaller,heights,heights.size());
         prev_smaller_element(prev_smaller,heights,heights.size());
         int area = 0;
         int ans = 0;
         for(int i = 0;i<n;i++){
           int length = heights[i];
           int breadth = next_smaller[i] - prev_smaller[i] - 1;
           area = length*breadth;
           ans = max(ans,area); 
         }

         return ans;
    }
};