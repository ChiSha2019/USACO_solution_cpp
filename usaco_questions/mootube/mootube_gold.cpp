/*strategy:
1.first sort edges and queries according to their weight and threshold
2.use two pointers to compare edges and queries from top to down.
    if this edge's weight is >= thredshold, then union the two nodes, traverse next edge
    until edge's weight is less then thredshold, then check next query
    during this process, document the size of each set.  
*/
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int Q;

class Edge{
    public:
    int a, b, w;
    Edge(){};
    Edge(int x, int y, int z){
        a = x;
        b = y;
        w = z;
    }

    void display(){
     cout << "a = " <<a <<", b = " << b << ", w = " << w << endl;
    }
};

bool compEdge(Edge e1, Edge e2){
    return e2.w < e1.w;
}

class Query{
    public:
    int threshold, startnode, nth;
    Query(){};
    Query(int x, int y, int z){
        threshold = x;
        startnode = y;
        nth = z;
    }
    void display(){
     cout << "threshold = " <<threshold <<", startnode = " 
     << startnode << ", nth = " << nth << endl;
    }
};

bool compQuery(Query q1, Query q2){
    return q2.threshold < q1.threshold;
}

class DisjointSet{
    public:
    int par[100001];
    int setSize[100001]; //index is the root of a set, value is the size of set

    DisjointSet(int n, int q){
        for (int i = 1; i < n+1; i++)
        {
            setSize[i] = 1;
        }

        for (int i = 1; i < n+1; i++){
            par[i] = i;
        }
        
    }

    int find(int x){
        if (x == par[x]){
            return x;
        }else{
            par[x] = find(par[x]);
            return par[x];
        }
    }

    int sizeOf(int x){
        return setSize[find(x)];
    }

    void union_set(int x, int y){
        int x_root = find(x);
        int y_root = find(y);
        if (x_root != y_root)
        {
            par[x_root] = y_root;
            setSize[y_root] = setSize[y_root] + setSize[x_root]; 


/*
            for (int i = 1; i <=4; i++)cout<<"par["<<i<<"]="<<par[i]<<endl;
            for (int i = 1; i <=4; i++)
            {
                cout<<"setSize["<<i<<"]="<<setSize[i]<<endl;
            }
            */
        }
    }
};

int main(){

    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);

    cin >> N >> Q;

    Edge edges[N-1];

    //read in edges
   
    for (int i = 0; i < N-1; i++)
    {
        int x,y,z;
        cin>> x >> y >> z;
        edges[i] = Edge(x,y,z);
    }

    sort(edges, edges +N-1, compEdge);

/*
    for (int i=0; i< N-1; i++)
    {
        edges[i].display();
    }
    */


    Query queries[Q];
    //read in queries
    for(int i =0 ; i< Q; i++){
        int x, y;
        cin >> x >>y;
        queries[i] = Query(x,y,i);
    }
    sort(queries, queries + Q, compQuery);

/*
    for (Query q: queries)
    {
        q.display();
    }
    */

    int idx_q = 0;
    int idx_e = 0;

    DisjointSet ds(N, Q);
    int answer[Q];

    while (idx_e < N-1 && idx_q < Q)
    {
        Edge theEdge = edges[idx_e];
        Query theQuery = queries[idx_q];
        if (theEdge.w >= theQuery.threshold)
        {        
            ds.union_set(theEdge.a, theEdge.b);
            idx_e++;
        }else{
            answer[theQuery.nth] = ds.sizeOf(theQuery.startnode)-1;
            idx_q++;
        }
    };

    //havent't finished checking all queries
    while (idx_q < Q)
    {
        Query theQuery = queries[idx_q];
        answer[theQuery.nth] = ds.sizeOf(theQuery.startnode)-1;
        idx_q++;
    }

    for (int ans: answer)
    {
        cout<<ans<<endl;
    }

    return 0;
    
}
