#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// A class to represent a graph object
class Graph
{
public:
    int V; // no. of vertices

    vector<vector<int>> adjList; // a vector of vectors to represent an adjacency list

    Graph(int V); // Constructor

    // function to add an edge to graph
    void adddirectedEdge(int v, int w);

    // function to add an undirected edge to graph
    void addundirectedEdge(int v, int w);

    // function to print the adjacency list representation of graph
    void printGraph(int n);

    // prints DFS traversal
    void DFS(int n);
};

Graph::Graph(int V)
{
    this->V = V;
    adjList.resize(V);
}

void Graph::adddirectedEdge(int v, int w)
{
    adjList[v].push_back(w); // Add w to v’s list.
}

void Graph::addundirectedEdge(int v, int w)
{
    adjList[v].push_back(w); // Add w to v’s list.
    adjList[w].push_back(v); // Add v to w's list
}

void Graph::printGraph(int n)
{
    cout << endl
         << "Graph representation using adjacency list:\n";
    for (int i = 0; i < n; i++)
    {
        // print the current vertex number
        cout << i << " --> ";

        // print all neighboring vertices of a vertex `i`
        for (int v : adjList[i])
        {
            cout << v << " ";
        }
        cout << endl;
    }
}

// Perform DFS on the graph
void Graph::DFS(int n)
{
    stack<int> st;
    // to keep track of whether a vertex is discovered as a source vertex or not
    vector<bool> discovered(n, false);

    // Perform DFS traversal from all undiscovered nodes to
    // cover all connected components of a graph
    for (int i = 0; i < n; i++)
    {
        st.push(i);
        if (discovered[i] == false)
        {
            vector<bool> visited(n, false);
            visited[i] = true;
            // start DFS traversal from vertex `i`
            while (!st.empty())
            {
                int v = st.top();
                st.pop();
                cout << v << "-->";
                // do for every edge (v, u)
                for (int adj : adjList[v])
                {
                    if (!visited[adj])
                    {
                        // mark it as discovered and enqueue it
                        visited[adj] = true;
                        st.push(adj);
                    }
                }
            }
            cout << endl;
            discovered[i] = true;
        }
    }
}

int main()
{
    char directed;
    cout << "Do you want to create a directed graph?(y/n)\n";
    cin >> directed;
    int n; // no. of vertices
    cout << "Enter the total number of vertices in the graph: ";
    cin >> n;
    Graph graph(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the number of adjacent vertices to " << i << " : ";
        int v;
        cin >> v;
        for (int j = 1; j <= v; j++)
        {
            cout << "Enter the " << j << "th adjacent vertex of " << i << " : ";
            int k;
            cin >> k;
            if (directed == 'y' || directed == 'Y')
                graph.adddirectedEdge(i, k);
            else if (directed == 'n' || directed == 'N')
                graph.addundirectedEdge(i, k);
        }
    }
    graph.printGraph(n);
    cout << endl
         << "DFS:" << endl;
    graph.DFS(n);
    return 0;
}
