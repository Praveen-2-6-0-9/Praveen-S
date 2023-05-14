#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
   set<int> vtd;
   vector<int> disc;
   vector<int> l;
   int time;
   vector<vector<int> > ans;
   void dfs(int node, int temp, vector<int> graph[]) {
      if (vtd.count(node))
      return;
      vtd.insert(node);
      disc[node] = l[node] = time;
      time++;
      for (int x : graph[node]) {
         if (x == temp)
         continue;
         if (!vtd.count(x)) {
            dfs(x, node, graph);
            l[node] = min(l[node], l[x]);
            if (disc[node] < l[x]) {
               ans.push_back({ node, x });
            }
         } else{
            l[node] = min(l[node], disc[x]);
         }
      }
   }
   vector<vector<int> > criticalConnections(int n, vector<vector<int> >& v) {
      disc.resize(n + 1);
      l.resize(n + 1);
      time = 0;
      vector<int> graph[n + 1];
      for (int i = 0; i < v.size(); i++) {
         int a = v[i][0];
         int b = v[i][1];
         graph[a].push_back(b);
         graph[b].push_back(a);
      }
      dfs(0, -1, graph);
      return ans;
   }
};
void print_vector(vector<vector<auto> > ans){
   cout << "[";
   for(int i = 0; i<ans.size(); i++){
      cout << "[";
      for(int j = 0; j <ans[i].size(); j++){
         cout << ans[i][j] << ", ";
      }
      cout << "],";
   }
   cout << "]"<<endl;
}
int main()
{
    std::vector<std::vector<int>> edges;
   Solution obj;
   int nodes;
   cout<< "enter number of nodes:";
   cin >> nodes;
   edges.resize(nodes,std::vector<int>(2));
   cout<< "enter elements in edges:\n";
   for(int i=0;i<nodes;i++){
        for(int j=0;j<2;j++){
            cout<<"enter "<<i+1<<" th "<<" connection "<<j+1<<" th node: ";
            
            cin>>edges[i][j];
    }
    }            
   print_vector(obj.criticalConnections(nodes,edges));
}
