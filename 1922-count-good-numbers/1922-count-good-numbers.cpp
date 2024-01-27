class Solution {
public:
long long mod=1e9+7;

    int countGoodNumbers(long long n) {
        long long result=1;
        if(n==0) return 1;
        else if(n%2==0){
            if((n/2)%2!=0){
                result=(4*(countGoodNumbers(n-1)%mod))%mod;
            }else{
                result=(countGoodNumbers(n/2))%mod;
                result=((result)*(result))%mod;
            }
        }else{
            result=(5*(countGoodNumbers(n-1)%mod))%mod;
        }
    return result;
    }
};