class Disjoint_set{
    public:
    vector<int>parent;
    vector<int>rank;
    Disjoint_set(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        parent[0]=0;
        rank[0]=0;
        for(int i=1 ;i <=n;i++){//O(N) Time Complexity 
            parent[i]=i;
            rank[i]=0;
        }
    }
    int find_parent(int n){
        if(parent[n]==n){return n;}
        return parent[n]=find_parent(parent[n]);//Path Compression to reduce further call s
    }
    void union_(int u, int v){
        int a=find_parent(u);
        int b=find_parent(v);
        if(rank[a]<rank[b]){
            parent[a]=b;
        }
        else if(rank[b]<rank[a]){
            parent[b]=a;
        }
        else{
            parent[a]=b;
            rank[b]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        Disjoint_set ds(n);//Create the Disjoint Set data structure 
        for(int i=0;i<n;i++){
            int u=ds.find_parent(edges[i][0]);// Finding the parent of each node or vertices 
            int v=ds.find_parent(edges[i][1]);
            if(u!=v){// if bouth doesnot have same parent , means are not connected yet 
                ds.union_(u,v);
            }
            else{return {edges[i][0],edges[i][1]};// it means they are connected beforehand and this the edge is an extra edge. // And thus can conclude this two verties are our answer 
            }

        }
        return {};
        
    }
};