//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
bool WordBreak(const vector<string> &wordList, const string &word) {
  // If the word is empty, it can be broken down into
  // an empty list of words
  if (word.empty())
    return true;

  int wordLen = word.length();

  // Check if the word can be broken down into
  // words from the wordList
  for (int i = 1; i <= wordLen; ++i) {
    string prefix = word.substr(0, i);

    if (find(wordList.begin(), wordList.end(), prefix) != wordList.end() &&
        WordBreak(wordList, word.substr(i))) {
      return true;
    }
  }

  return false;
}

    int wordBreak(string A, vector<string> &B) {
        //code here
        return WordBreak(B,A);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends