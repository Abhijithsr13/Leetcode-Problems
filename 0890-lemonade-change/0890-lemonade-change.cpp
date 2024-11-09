class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // f will store the 5s and t will store the 10s
        int f=0;int t=0;
        int n=bills.size();
        for(int i=0;i<n;i++){
          if(bills[i]==5){
            f++;
          }
          else if(bills[i]==10){
            if(f){
              f--;
              t++;
            }
            else return false;
          }
          else {
            if(f&&t){
              t--;
              f--;
            }
            else if(f>=3) 
            f-=3;
            else return false;
          }
        }
        return true;
    }
};