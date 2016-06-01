#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph
{
private:
    int num_of_vertices;
    vector<int> *Adj;
//    vector< vector<int> > Adj;
public:
    Graph(int V);
    ~Graph();
    void addEdge(int from, int to);
    void BFS(int Start);
    void DFS(int Start);
};

Graph::Graph(int V)
{
    this->num_of_vertices = V;
    Adj = new vector<int>[V];
}

Graph::~Graph() {
    delete[] Adj;
}

void Graph::addEdge(int from, int to)
{
    Adj[from].push_back(to);
}

void Graph::BFS(int Start)
{
    bool* visited = new bool[this->num_of_vertices]();
//    std::vector<bool> visited(num_of_vertices);
    queue<int> queue;
    queue.push(Start);

    cout << "BFS: ";
    while(!queue.empty())
    {
        Start = queue.front();
        cout << Start << " ";
        visited[Start] = true;
        queue.pop();
        for (vector<int>::iterator i = Adj[Start].begin(); i != Adj[Start].end(); i++)
        {
            if (!visited[*i])
                queue.push(*i);
        }
    }
    cout << endl;
    delete[] visited;
}

void Graph::DFS(int Start)
{
    bool* visited = new bool[this->num_of_vertices]();
//    std::vector<bool> visited(num_of_vertices);
    stack<int> stack;
    stack.push(Start);

    cout << "DFS: ";
    while(!stack.empty())
    {
        int top = stack.top();
        cout << top << " ";
        stack.pop();
        visited[top] = true;
        for(vector<int>::iterator i = Adj[top].begin(); i != Adj[top].end(); i++)
        {
            if (!visited[*i])
                stack.push(*i);
        }
    }
    cout << endl;
    delete[] visited;
}

int main() {

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.BFS(2);

    g.DFS(2);

    return 0;
}