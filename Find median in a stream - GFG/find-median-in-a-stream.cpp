//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int> maxi;
    priority_queue<int,vector<int>,greater<int> > mini;
    int num;
    void insertHeap(int &x)
    {
        num=x;
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(maxi.size()==0){
            maxi.push(num);
        }
        else{
            if(maxi.size()<mini.size()){
                if(num>mini.top()){
                    maxi.push(mini.top());
                    mini.pop();
                    mini.push(num);
                }
                else{
                    maxi.push(num);
                }
            }
            else if(maxi.size()>mini.size()){
                if(num<maxi.top()){
                    mini.push(maxi.top());
                    maxi.pop();
                    maxi.push(num);
                }
                else{
                    mini.push(num);
                }
            }
            else{
                if(num> maxi.top() && num> mini.top()){
                    maxi.push(mini.top());
                    mini.pop();
                    mini.push(num);
                }
                else{
                    maxi.push(num);
                }
            }
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        int sz1= maxi.size();
        int sz2=mini.size();
        if(sz1==sz2){
            double ans= double(maxi.top()+mini.top())/2;
            return ans;
        }
        else{
            double ans= double(maxi.top());
            return ans;
        }
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends