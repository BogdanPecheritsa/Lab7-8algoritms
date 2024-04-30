#include <iostream>
#include <vector>
#include <queue>
#include <stack>

class Graph {
    int numVertices;
    std::vector<std::vector<int>> adjLists;

public:
    Graph(int vertices) : numVertices(vertices), adjLists(vertices, std::vector<int>(vertices, 0)) {}

    void addEdge(int src, int dest, int weight) {
        adjLists[src][dest] = weight;
    }

    void BFS(int startVertex) {
        std::vector<bool> visited(numVertices, false);
        std::queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty()) {
            int vertex = q.front();
            std::cout << vertex << " ";
            q.pop();
            for (int i = 0; i < numVertices; i++) {
                if (adjLists[vertex][i] > 0 && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    void DFS(int startVertex) {
        std::vector<bool> visited(numVertices, false);
        std::stack<int> st;

        st.push(startVertex);

        while (!st.empty()) {
            int vertex = st.top();
            st.pop();

            if (!visited[vertex]) {
                std::cout << vertex << " ";
                visited[vertex] = true;
            }
            for (int i = 0; i < numVertices; i++) {
                if (adjLists[vertex][i] > 0 && !visited[i]) {
                    st.push(i);
                }
            }
        }
    }
};

int main() {
    Graph g(21);

    g.addEdge(0, 1, 135);
    g.addEdge(1, 2, 80);
    g.addEdge(2, 3, 100);
    g.addEdge(3, 4, 68);

    g.addEdge(0, 1, 135);
    g.addEdge(1, 5, 38);
    g.addEdge(5, 6, 73);
    g.addEdge(6, 7, 110);
    g.addEdge(7, 8, 104);
    g.addEdge(8, 9, 104);

    g.addEdge(0, 1, 135);
    g.addEdge(1, 10, 115);

    g.addEdge(0, 11, 78);
    g.addEdge(11, 12, 115);

    g.addEdge(0, 11, 78);
    g.addEdge(11, 13, 146);
    g.addEdge(13, 14, 105);
    g.addEdge(14, 15, 105);

    g.addEdge(0, 11, 78);
    g.addEdge(11, 16, 181);
    g.addEdge(16, 17, 130);

    g.addEdge(0, 18, 128);
    g.addEdge(18, 19, 175);

    g.addEdge(0, 18, 128);
    g.addEdge(18, 20, 109);

    std::cout << "BFS traversal starting from node 0: ";
    g.BFS(0);
    std::cout << "\n";

    std::cout << "DFS traversal starting from node 0: ";
    g.DFS(0);
    std::cout << "\n";

    return 0;
}