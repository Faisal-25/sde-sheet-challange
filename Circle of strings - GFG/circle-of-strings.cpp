//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void dfs(int node, vector<int> adj[], int visited[]){
        visited[node] = 1;
        for(auto u: adj[node]){
            if(!visited[u])
            dfs(u, adj, visited);
        }
    }
    
    int isCircle(int N, vector<string> A){
        // We use the concept of Euler circuit.If each vertex has indegree equal 
        // to outdegree and there is only one strongly connected component then
        // the graph has an Euler circuit..then we return 1 else 0
        int i;
        vector<int> adj[26], adjr[26];
        
        // creating a directed graph where there is an edge from the first  
        // letter of every string to the last letter of the string and the 
        // transpose graph
        for(i = 0;i < N;i++){
	        int x = A[i].size()-1;
	        adj[(A[i][0]-'a')].emplace_back((A[i][x]-'a'));
	        adjr[(A[i][x]-'a')].emplace_back((A[i][0]-'a'));
	    }
	    
	   // calculating the indegree of each vertex
	    int indeg[26] = {0};
	    for(i = 0;i < 26;i++){
	        if(adj[i].size() > 0){
	            for(auto u: adj[i])
	            indeg[u]++;
	        }
	    }
	    
	   // checking if the indegree of every vertex is equal to the 
	   // outdegree of that vertex
	    for(i = 0;i < 26;i++){
	        if(adj[i].size() > 0 and indeg[i] != adj[i].size()){
	            return 0;
	        }
	    }
	    
	   // checking strongly connected component using Kosaraju's algorithm
	    int visited[26] = {0};
	    for(i = 0;i < 26;i++){
	        if(indeg[i] > 0)
	        break;
	    }
	    int n = i;
	    
	   // first dfs call and checking if all the nodesare visited or not
	    dfs(n, adj, visited);
	    for(i = 0;i < 26;i++){
	        if(adj[i].size() and !visited[i]){
	            return 0;
	        }
	    }
	    
	   // dfs call on transpose graph for getting strongly connected component
	    for(i = 0;i < 26;i++) 
	    visited[i] = 0;
	    
        dfs(n, adjr, visited);
        for(i = 0;i < 26;i++){
            if(adjr[i].size() and !visited[i]){
                return 0;
            }
        }
        
        // return 1 as there is an Euler circuit
        return 1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends