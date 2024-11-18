class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
         int leftSum=0;
        int rightSum=0;
        int sum;
        int n=cardPoints.size();
        for(int i=0;i<k;i++){
          leftSum=leftSum+cardPoints[i];
        }
          sum=leftSum;
         int rindex=n-1;
        for(int i=k-1;i>=0;i--){
          leftSum=leftSum-cardPoints[i];
          rightSum=rightSum+ cardPoints[rindex];
          rindex=rindex-1;
          sum=max(sum,leftSum+rightSum);
        }
        return sum;
    }
};