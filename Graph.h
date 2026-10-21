
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Edge
{
    int destination;
    double distance;
};

class Graph
{
private:
    vector<string> locations;
    vector<vector<Edge>> adjacencyList;

public:

    void addLocation(const string& name)
    {
        locations.push_back(name);
        adjacencyList.push_back({});
        cout << "\nLocation added successfully!";
    }

    void displayLocations() const
    {
        cout << "\n\n========== LOCATIONS ==========\n";

        if (locations.empty())
        {
            cout << "No locations available.\n";
            return;
        }

        for (int i = 0; i < static_cast<int>(locations.size()); i++)
        {
            cout << i << " -> " << locations[i] << '\n';
        }
    }

    void addRoad(int source, int destination, double distance)
    {
        if (source < 0 || destination < 0 ||
            source >= static_cast<int>(locations.size()) ||
            destination >= static_cast<int>(locations.size()))
        {
            cout << "\nInvalid location ID!";
            return;
        }

        if (source == destination || distance <= 0)
        {
            cout << "\nEnter different locations and a positive distance.";
            return;
        }

        adjacencyList[source].push_back({destination, distance});
        adjacencyList[destination].push_back({source, distance});

        cout << "\nRoad added successfully!";
    }

    void displayGraph() const
    {
        cout << "\n\n========== ROAD NETWORK ==========\n";

        for (int i = 0; i < static_cast<int>(locations.size()); i++)
        {
            cout << locations[i] << " -> ";

            for (const Edge& edge : adjacencyList[i])
            {
                cout << "(" << locations[edge.destination]
                     << ", " << edge.distance << " km) ";
            }

            cout << '\n';
        }
    }

    // These functions MUST stay inside the Graph class
    const vector<string>& getLocations() const
    {
        return locations;
    }

    const vector<vector<Edge>>& getGraph() const
    {
        return adjacencyList;
    }
};

#endif
