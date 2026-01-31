#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    private:
        vector<vector<int>> adj;
        int V;

        // bfs for connected graph
        void bfs(int start, vector<bool>& visited) {

            // declare a queue for level order traversal
            queue<int> q;

            // mark start as visited
            // And push start into queue
            visited[start] = true;
            q.push(start);

            // iterate until queue is empty
            while(!q.empty()) {

                // retrive front
                int node = q.front();

                // pop front
                q.pop();

                // process front
                cout << node << " ";

                // iterate over each neighbours of curr node
                for(int neighbour: adj[node]) {
                    // visit neighbour if not visited
                    // push into queue
                    if(!visited[neighbour]) {
                        visited[neighbour] = true;
                        q.push(neighbour);
                    }
                }
            }
        }

        // check cycle in bfs
        bool bfsCycle(int start, vector<bool>& visited) {

            // create a queue to store visited node along with parent
            queue<pair<int, int>> q;

            // push start into queue
            q.push({start, -1});

            // iterate until queue is empty
            while(!q.empty()) {

                // retreive curr node with parent
                auto& [node, parent] = q.front(); 

                // pop curr node from queue
                q.pop();

                // iterate over each neighbours of curr node
                for(int neighbour: adj[node]) {
                    // visit unvisited neighbour
                    // push into queue
                    if(!visited[neighbour]) {
                        visited[neighbour] = true;
                        q.push({neighbour, node});
                    }
                    // if already visited - check for cycle
                    // if not equal to parent - cycle exist
                    if(neighbour != parent) {
                        return true;
                    }
                }
            }
            return false;
        }

        // dfs for connected graph
        void dfs(int node, vector<bool>& visited) {
            // visit node
            visited[node] = true;

            // process visited node
            cout << node << " ";

            // iterate over each neighbours of curr node
            for(int neighbour: adj[node]) {
                // visit the unvisited neighbour
                // push into stack
                if(!visited[neighbour]) {
                    dfs(neighbour, visited);
                }
            }
            
        }

        // check cycle in dfs
        bool dfsCycle(int node, int parent, vector<bool>& visited) {

            // visit the start node
            visited[node] = true;

            // itearate over neighbours of curr node
            for(int neighbour: adj[node]) {
                // visit unvisited nodes
                // push into stack
                if(!visited[neighbour]) {
                    if(dfsCycle(neighbour, node, visited)) return true;
                }
                // if already visited
                // if not equal to parent - cycle exist
                else if(neighbour != parent) {
                    return true;
                }

            }
            return false;

        }

    public:
        Graph(int v) {
            V = v;
            adj.resize(V);
        }

        // undirected graph
        void addEdge(int u, int v) {
            if(u < 0 || v < 0 || u >= V || v >= V) return;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        /* directed graph
        void addEdge(int u, int v) {
            adj[u].push_back(v);
        }
        */

        // bfs for connected + disconnected graph
        void bfsAll() {

            // initalize array to keep track of visited node 
            // to avoid infinite loop
            vector<bool> visited(V, false);

             // iterate over every graph component (connected or disconnected)
            for(int i = 0; i < V; i++) {
                if(!visited[i]) {
                    bfs(i, visited);
                    cout << endl;
                }
            }
        }

        // bfs for connected + disconnected graph
        void bfsAll() {

            // initalize array to keep track of visited node 
            // to avoid infinite loop
            vector<bool> visited(V, false);

             // iterate over every graph component (connected or disconnected)
            for(int i = 0; i < V; i++) {
                if(!visited[i]) {
                    bfs(i, visited);
                    cout << endl;
                }
            }
        }

        // check for cycle
        bool isBfsCycleExist() {

            // initialize array to keep track of visited nodes 
            // to avoid inifinite loop
            vector<bool> visited(V, false);

            // iterate over each component (connected or disconnected)
            for(int i = 0; i < V; i++) {
                if(!visited[i]) {
                    if(bfsCycle(i, visited)) return true;
                }
            }
            return false;
        }

        // dfs for connected + disconnected graph
        void dfsAll() {

            // initalize array to keep track of visited node 
            // to avoid infinite loop 
            vector<bool> visited(V, false);

            // iterate over every graph component (connected or disconnected)
            for(int i = 0; i < V; i++) {
                // visit node of each component if not visited
                if(!visited[i]) {
                    dfs(i, visited);
                    cout << endl;
                }
            }
        }

        // check for cycle
        bool isDfsCycleExist() {
            // initialize an array to keep track of unvisited nodes
            // to avoid infinte loop
            vector<bool> visited(V, false);

            // itearte over each component (connected or disconnected)
            for(int i = 0; i < V; i++) {
                if(!visited[i]) {
                    if(dfsCycle(i, -1, visited)) return true;
                }
            }
            return false;
        }
};
 
int main() {

    Graph g(5);
    
    // Connected BFS 
    // g.addEdge(0, 1);
    // g.addEdge(0, 2);
    // g.addEdge(1, 3);
    // g.addEdge(1, 4);

    // Disconnected BFS
    // g.addEdge(0, 1);
    // g.addEdge(1, 4);
    // g.addEdge(2, 3);

    // g.bfsAll();



    // Connected DFS
    // g.addEdge(0, 1);
    // g.addEdge(0, 4);
    // g.addEdge(1, 2);
    // g.addEdge(2, 3);

    // Disconnected BFS
    // g.addEdge(0, 1);
    // g.addEdge(1, 4);
    // g.addEdge(2, 3);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 3);

    g.dfsAll();

    cout << "Does cycle exist: " << g.isDfsCycleExist();



}