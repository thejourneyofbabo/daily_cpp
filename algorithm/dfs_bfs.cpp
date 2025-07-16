// DFS & BFS algorithms implementation
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

static vector<vector<int>> A;  // Adjacency list representation of graph
static vector<bool> visited;   // Array to track visited nodes

// Function declarations
void DFS(int node);
void BFS(int node);

int main() {
  // Remove sync optimization when using interactive input/output
  // ios::sync_with_stdio(false);
  // cin.tie(NULL);
  // cout.tie(NULL);

  // ========== TERMINAL INPUT SECTION ==========
  int N, M, Start;
  cout << "Enter N (nodes), M (edges), Start (starting node): ";
  cout.flush();            // Force output to appear immediately
  cin >> N >> M >> Start;  // INPUT: N(nodes) M(edges) Start(starting node)

  A.resize(N + 1);  // Resize adjacency list (1-indexed)

  // INPUT: Read M edges and build adjacency list
  cout << "Enter " << M << " edges (format: node1 node2):\n";
  for (int i = 0; i < M; i++) {
    int s, e;
    cout << "Edge " << (i + 1) << ": ";
    cout.flush();       // Force output to appear immediately
    cin >> s >> e;      // INPUT: Read edge from s to e
    A[s].push_back(e);  // Add e to adjacency list of s
    A[e].push_back(s);  // Add s to adjacency list of e (undirected graph)
  }

  // Sort adjacency lists to visit smaller numbered nodes first
  for (int i = 1; i <= N; i++) {
    sort(A[i].begin(), A[i].end());
  }

  // ========== TERMINAL OUTPUT SECTION ==========
  // DFS OUTPUT: Execute DFS and print result
  cout << "\nDFS OUTPUT: ";
  visited = vector<bool>(N + 1, false);  // Initialize visited array
  DFS(Start);    // DFS OUTPUT: Start DFS from starting node
  cout << "\n";  // DFS OUTPUT: New line after DFS result

  // Reset visited array for BFS
  fill(visited.begin(), visited.end(), false);

  // BFS OUTPUT: Execute BFS and print result
  cout << "BFS OUTPUT: ";
  BFS(Start);    // BFS OUTPUT: Start BFS from starting node
  cout << "\n";  // BFS OUTPUT: New line after BFS result

  return 0;
}

// DFS implementation - Depth First Search
void DFS(int node) {
  cout << node << " ";   // DFS OUTPUT: Print current node to terminal
  visited[node] = true;  // Mark current node as visited

  // Visit all unvisited adjacent nodes recursively
  for (int i : A[node]) {
    if (!visited[i]) {
      DFS(i);  // Recursive call for unvisited node
    }
  }
}

// BFS implementation - Breadth First Search
void BFS(int node) {
  queue<int> myqueue;    // Queue for BFS
  myqueue.push(node);    // Add starting node to queue
  visited[node] = true;  // Mark starting node as visited

  // Continue until queue is empty
  while (!myqueue.empty()) {
    int now_node = myqueue.front();  // Get front node from queue
    myqueue.pop();                   // Remove front node
    cout << now_node << " ";  // BFS OUTPUT: Print current node to terminal

    // Add all unvisited adjacent nodes to queue
    for (int i : A[now_node]) {
      if (!visited[i]) {
        visited[i] = true;  // Mark as visited
        myqueue.push(i);    // Add to queue
      }
    }
  }
}
