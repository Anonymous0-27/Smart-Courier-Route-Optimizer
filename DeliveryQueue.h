#ifndef DELIVERY_QUEUE_H
#define DELIVERY_QUEUE_H

#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct DeliveryTask
{
    int parcelId;
    int priority;
};


struct ComparePriority
{
    bool operator()(
        const DeliveryTask& a,
        const DeliveryTask& b)
    {
        return a.priority > b.priority;
    }
};


class DeliveryQueue
{
private:

    priority_queue<
        DeliveryTask,
        vector<DeliveryTask>,
        ComparePriority
    > tasks;


public:

    void addTask(
        int parcelId,
        int priority)
    {
        tasks.push({
            parcelId,
            priority
        });
    }


    void processTasks()
    {
        if (tasks.empty())
        {
            cout << "\nNo delivery tasks.";
            return;
        }

        cout << "\n\n========== DELIVERY PRIORITY ==========\n";

        while (!tasks.empty())
        {
            DeliveryTask task =
                tasks.top();

            tasks.pop();

            cout << "\nParcel ID: "
                 << task.parcelId;

            cout << "\nPriority: ";

            if (task.priority == 1)
                cout << "Urgent";
            else if (task.priority == 2)
                cout << "Express";
            else
                cout << "Normal";

            cout << "\n-----------------------------";
        }
    }
};

#endif