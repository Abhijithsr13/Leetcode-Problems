class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
         ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        int ct = 0;
        int f = flowerbed.size();

        if(f==1 && flowerbed[0]==0 && n<=1) return true; 
        if(flowerbed[0]==0 && flowerbed[1]==0) {
            flowerbed[0]=1;
            ct++;
        }
        
        for (int i = 1; i < f - 1; i++) {
            
            if (flowerbed[i] == 0 && flowerbed[i + 1] == 0 &&
                flowerbed[i - 1] == 0) {
                ct++;
                flowerbed[i]=1;
            }
        }
        if(flowerbed[f-1]==0 && flowerbed[f-2]==0) {
            flowerbed[f-1]=1;
            ct++;
        }
        return ct >= n;
    }
};