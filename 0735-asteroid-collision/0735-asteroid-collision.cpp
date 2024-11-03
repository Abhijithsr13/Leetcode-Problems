class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
         stack<int>li;
         int n=asteroids.size();
        for(int i=0;i<n;i++){
            if(asteroids[i]>0)
            li.push(asteroids[i]);
            else{
                while(!li.empty()&&li.top()>0 && li.top()< abs(asteroids[i])){
                    li.pop();
                }
                if(!li.empty()&&li.top()==abs(asteroids[i]))
                li.pop();
                else if( li.empty()||li.top()<0)
                li.push(asteroids[i]);
            }
        }
            int N=li.size();
            vector<int>ans(N);
            int i=N-1;
            while(!li.empty()){
                ans[i--]=li.top();
                li.pop();
            }
            return ans;
    }
};