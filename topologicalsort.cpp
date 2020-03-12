#include<iostream>
#include <list>
#include <stack>
using namespace std;

class G {
   int n;
   list<int> *adj;

   void topologicalSort(int v, bool visited[], stack<int> &Stack);
   
   public:
   G(int n);
   void addEd(int v, int w);
   void topoSort();
};

G::G(int n) {
   this->n = n;
   adj = new list<int> [n];
}

void G::addEd(int v, int w) {
   adj[v].push_back(w);
}

void G::topologicalSort(int v, bool visited[], stack<int> &Stack) {
   visited[v] = true;
   list<int>::iterator i;
   for (i = adj[v].begin(); i != adj[v].end(); ++i) if (!visited[*i]) topologicalSort(*i, visited, Stack);
    Stack.push(v);
}

void G::topoSort() {
   stack<int> Stack;
   bool *visited = new bool[n];

   for (int i = 0; i < n; i++) visited[i] = false;
   for (int i = 0; i < n; i++) if (visited[i] == false) topologicalSort(i, visited, Stack);
   while (Stack.empty() == false) {
        cout << Stack.top() << " ";
        Stack.pop();
   }
}

int main() {
   G g(6);
   g.addEd(4, 2);
   g.addEd(5, 1);
   g.addEd(4, 0);
   g.addEd(3, 1);
   g.addEd(1, 3);
   g.addEd(3, 2);
   cout << "Topological Sort of the given graph \n";
   g.topoSort();
   return 0;
}
