#include <iostream>
#include <vector>
#include <string>
#include "Graph.h"
#include "Dijkstra.h"
#include "DeliveryQueue.h"


using namespace std;

// ===============================
// PARCEL CLASS
// ===============================

class Parcel
{
private:
    int id;
    string sender;
    string receiver;
    string source;
    string destination;
    double weight;
    int priority;

public:

    Parcel(int id,
           string sender,
           string receiver,
           string source,
           string destination,
           double weight,
           int priority)
    {
        this->id = id;
        this->sender = sender;
        this->receiver = receiver;
        this->source = source;
        this->destination = destination;
        this->weight = weight;
        this->priority = priority;
    }

    void display() const
    {
        cout << "\n-----------------------------";
        cout << "\nParcel ID      : " << id;
        cout << "\nSender         : " << sender;
        cout << "\nReceiver       : " << receiver;
        cout << "\nSource         : " << source;
        cout << "\nDestination    : " << destination;
        cout << "\nWeight         : " << weight << " kg";

        cout << "\nPriority       : ";

        if (priority == 1)
            cout << "Urgent";
        else if (priority == 2)
            cout << "Express";
        else
            cout << "Normal";

        cout << "\n-----------------------------\n";
    }
};


// ===============================
// VEHICLE CLASS
// ===============================

class Vehicle
{
private:
    int vehicleId;
    string vehicleNumber;
    double capacity;

public:

    Vehicle(int vehicleId,
            string vehicleNumber,
            double capacity)
    {
        this->vehicleId = vehicleId;
        this->vehicleNumber = vehicleNumber;
        this->capacity = capacity;
    }

    void display() const
    {
        cout << "\n-----------------------------";
        cout << "\nVehicle ID     : " << vehicleId;
        cout << "\nVehicle Number : " << vehicleNumber;
        cout << "\nCapacity       : " << capacity << " kg";
        cout << "\n-----------------------------\n";
    }
};


// ===============================
// MAIN FUNCTION
// ===============================

int main()
{
    vector<Parcel> parcels;
    vector<Vehicle> vehicles;
    Graph roadNetwork;
    DeliveryQueue deliveryQueue;

    int choice;

    do
    {
        cout << "\n\n========================================";
        cout << "\n     SMART COURIER ROUTE OPTIMIZER";
        cout << "\n========================================";

        cout << "\n1. Add Parcel";
        cout << "\n2. View Parcels";
        cout << "\n3. Add Vehicle";
        cout << "\n4. View Vehicles";
        cout << "\n5. Add Location";
        cout << "\n6. View Locations";
        cout << "\n7. Add Road";
        cout << "\n8. View Road Network";
        cout << "\n9. Find Shortest Route";
        cout << "\n10. Add Delivery Task";
        cout << "\n11. Process Priority Deliveries";
        cout << "\n0. Exit";
        cout << "\n\nEnter your choice: ";
        cin >> choice;


        // ===============================
        // ADD PARCEL
        // ===============================

        if (choice == 1)
        {
            int id;
            string sender;
            string receiver;
            string source;
            string destination;
            double weight;
            int priority;

            cout << "\nEnter Parcel ID: ";
            cin >> id;

            cout << "Enter Sender: ";
            cin >> sender;

            cout << "Enter Receiver: ";
            cin >> receiver;

            cout << "Enter Source Location: ";
            cin >> source;

            cout << "Enter Destination Location: ";
            cin >> destination;

            cout << "Enter Weight (kg): ";
            cin >> weight;

            cout << "Enter Priority";
            cout << "\n1 = Urgent";
            cout << "\n2 = Express";
            cout << "\n3 = Normal";
            cout << "\nChoice: ";
            cin >> priority;


            parcels.emplace_back(
                id,
                sender,
                receiver,
                source,
                destination,
                weight,
                priority
            );

            cout << "\nParcel added successfully!";
        }


        // ===============================
        // VIEW PARCELS
        // ===============================

        else if (choice == 2)
        {
            if (parcels.empty())
            {
                cout << "\nNo parcels available.";
            }
            else
            {
                cout << "\n\n========== PARCEL LIST ==========";

                for (const Parcel& parcel : parcels)
                {
                    parcel.display();
                }
            }
        }


        // ===============================
        // ADD VEHICLE
        // ===============================

        else if (choice == 3)
        {
            int id;
            string number;
            double capacity;

            cout << "\nEnter Vehicle ID: ";
            cin >> id;

            cout << "Enter Vehicle Number: ";
            cin >> number;

            cout << "Enter Vehicle Capacity (kg): ";
            cin >> capacity;

            vehicles.emplace_back(
                id,
                number,
                capacity
            );

            cout << "\nVehicle added successfully!";
        }


        // ===============================
        // VIEW VEHICLES
        // ===============================

        else if (choice == 4)
        {
            if (vehicles.empty())
            {
                cout << "\nNo vehicles available.";
            }
            else
            {
                cout << "\n\n========== VEHICLE LIST ==========";

                for (const Vehicle& vehicle : vehicles)
                {
                    vehicle.display();
                }
            }
        }
        else if (choice == 5)
        {
            string name;

            cout << "\nEnter Location Name: ";
            cin >> name;

            roadNetwork.addLocation(name);
        }
        else if (choice == 6)
        {
            roadNetwork.displayLocations();
        }
        else if (choice == 7)
        {
            int source;
            int destination;
            double distance;

            roadNetwork.displayLocations();

            cout << "\nEnter Source Location ID: ";
            cin >> source;

            cout << "Enter Destination Location ID: ";
            cin >> destination;

            cout << "Enter Road Distance (km): ";
            cin >> distance;

            roadNetwork.addRoad(source, destination, distance);
        }
        else if (choice == 8)
        {
            roadNetwork.displayGraph();
        }
        else if (choice == 9)
{
    int source;
    int destination;

    roadNetwork.displayLocations();

    cout << "\nEnter Source Location ID: ";
    cin >> source;

    cout << "Enter Destination Location ID: ";
    cin >> destination;

    Dijkstra::shortestPath(
        roadNetwork.getGraph(),
        roadNetwork.getLocations(),
        source,
        destination
    );
}
        
 
else if (choice == 10)
{
    int parcelId;
    int priority;

    cout << "\nEnter Parcel ID: ";
    cin >> parcelId;

    cout << "Enter Priority (1=Urgent, 2=Express, 3=Normal): ";
    cin >> priority;

    deliveryQueue.addTask(
        parcelId,
        priority
    );

    cout << "\nDelivery task added!";
}
else if (choice == 11)
{
    deliveryQueue.processTasks();
}
        else if (choice == 0)
        {
            cout << "\n\nThank you for using Smart Courier Route Optimizer!";
        }
        else
        {
            cout << "\nInvalid choice. Please try again.";
        }

    } while (choice != 0);


    return 0;
}