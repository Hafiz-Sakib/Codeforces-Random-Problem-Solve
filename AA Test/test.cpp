#include <bits/stdc++.h>
using namespace std;

const int inf = 1e7;
const int n = 1e3;

vector<pair<int, int>> g[n] = {
    {},                                         // node 0
    {{1, 9}, {4, 7}, {3, 3}},                   // node 1
    {{4, 8}, {5, 11}, {7, 6}, {3, 17}, {2, 2}}, // node 2
    {{4, 5}},                                   // node 3
    {{6, 5}, {5, 12}},                          // node 4
    {{7, 13}, {6, 6}},                          // node 5
    {{7, 8}},                                   // node 6
    {}                                          // node 7
};
;
// { node , weight}

void dijkstra(int source)
{
    vector<int> distance(n, inf);
    vector<bool> visited(n, 0);

    set<pair<int, int>> st;
    // {weight , node}

    st.insert({0, source});
    distance[source] = 0;

    while (!st.empty())
    {
        auto node = *st.begin();
        // will give the minimum pair {weight , node}

        int v = node.second;
        int dist = node.first;
        st.erase(st.begin());

        if (visited[v])
        {
            continue;
        }

        visited[v] = 1;

        // Traverse to the child of v,for relaxation
        for (auto child : g[v])
        {
            int child_v = child.first;
            int wt = child.second;

            // Relaxation
            if ((distance[v] + wt) < distance[child_v])
            {
                distance[child_v] = distance[v] + wt;
                st.insert({distance[child_v], child_v});
            }
        }
    }
    cout << "Node\tDistance from " << source << endl;
    for (int i = 0; i < n; ++i)
    {
        if (distance[i] != inf)
        {
            cout << i << "\t" << distance[i] << endl;
        }
    }
}

int main()
{
    int node, edge;
    cin >> node >> edge;
    for (int i = 0; i < edge; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        g[u].push_back({v, wt});
        g[v].push_back({u, wt});
        // u indexed node connected with v node containing wt weight
    }
    dijkstra(0);

    return 0;
}

/*
8 17
0 1 9
0 4 7
0 3 3
1 4 8
1 5 11
1 7 6
1 3 17
1 2 2
2 7 3
2 6 11
2 5 19
3 4 5
4 6 5
4 5 12
5 7 13
5 6 6
6 7 8
*/
