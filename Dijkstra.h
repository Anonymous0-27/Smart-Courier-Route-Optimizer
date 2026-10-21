#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

class Dijkstra
{
public:

    static void shortestPath(
        const vector<vector<Edge>>& graph,
        const vector<string>& locations,
        int source,
        int destination)
    {
        int n = graph.size();

        const double INF =
            numeric_limits<double>::infinity();

        vector<double> distance(n, INF);

        vector<int> parent(n, -1);

        priority_queue<
            pair<double, int>,
            vector<pair<double, int>>,
            greater<pair<double, int>>
        > pq;


        distance[source] = 0;

        pq.push({0, source});


        while (!pq.empty())
        {
            double currentDistance =
                pq.top().first;

            int current =
                pq.top().second;

            pq.pop();


            if (currentDistance >
                distance[current])
            {
                continue;
            }


            for (const Edge& edge : graph[current])
            {
                int next =
                    edge.destination;

                double newDistance =
                    currentDistance +
                    edge.distance;


                if (newDistance <
                    distance[next])
                {
                    distance[next] =
                        newDistance;

                    parent[next] =
                        current;

                    pq.push({
                        newDistance,
                        next
                    });
                }
            }
        }


        if (distance[destination] == INF)
        {
            cout << "\nNo route exists!";
            return;
        }


        vector<int> path;

        int current = destination;

        while (current != -1)
        {
            path.push_back(current);
            current = parent[current];
        }

        reverse(path.begin(), path.end());


        cout << "\n\n========== SHORTEST ROUTE ==========\n";

        cout << "\nRoute: ";

        for (int i = 0; i < path.size(); i++)
        {
            cout << locations[path[i]];

            if (i != path.size() - 1)
                cout << " -> ";
        }

        cout << "\nTotal Distance: "
             << distance[destination]
             << " km\n";
    }
};

#endif