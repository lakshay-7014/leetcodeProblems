class Solution {
    private:
    vector<int> nextIndex(vector<int>& heights , int n){
        stack<int>s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            int curr=heights[i];
            while(s.top()!=-1 && heights[s.top()]>= curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
     vector<int> prevIndex(vector<int>& heights , int n){
        stack<int>s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int curr=heights[i];
            while(s.top()!=-1 && heights[s.top()]>= curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> prev;
        vector<int> next;
        prev = prevIndex(heights,n);
        next=nextIndex(heights,n);
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int l=heights[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int b=next[i]-prev[i]-1;
            int area= l*b;
            ans=max(ans,area);
        }
        return ans;
    }
};