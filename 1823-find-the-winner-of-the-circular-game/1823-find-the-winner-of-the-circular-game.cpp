class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> temp;
  for (int i = 0; i < n; i++) {
    temp.push_back(i + 1);
  }
  int size = temp.size();
  int i = 0;

  while (size != 1) {
    i = (i + k - 1) % size;

    temp.erase(temp.begin() + i);
    size--;
  }
        int ans=temp[0];
        return ans;
    }
};