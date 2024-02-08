class Solution {
public:
    int numSquares(int n) {
        
     if(ceil(sqrt(n))==floor(sqrt(n)))
            return 1;
        while(n%4==0)   //Remove 4^a term
            n/=4;
        
        if(n%8==7)      //check if the no now is in the form of (8b + 7)
            return 4;
        
        for(int i=1;i*i<=n;++i)
        {
            int base = sqrt(n-i*i);
            if(base*base==(n-i*i))
                return 2;
        }
        return 3;
    }
};
