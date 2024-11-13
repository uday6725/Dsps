#include <iostream>
using namespace std;

class PizzaParlor {
    int front, rear, maxSize;
    int *queue;

public:
    PizzaParlor(int size) : front(-1), rear(-1), maxSize(size) {
        queue = new int[maxSize];
    }

    bool isFull() {
        return (rear + 1) % maxSize == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void placeOrder(int orderID) {
        if (isFull()) {
            cout << "\n  Order Queue Full! Unable to place order #" << orderID << ".\n";
        } else {
            if (front == -1) front = 0;
            rear = (rear + 1) % maxSize;
            queue[rear] = orderID;
            cout << " Order #" << orderID << " placed successfully.\n";
        }
    }

    void serveOrder() {
        if (isEmpty()) {
            cout << "\n⚠️  No orders to serve.\n";
        } else {
            cout << "🍕 Serving Order #" << queue[front] << ".\n";
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % maxSize;
            }
        }
    }

    void displayOrders() {
        if (isEmpty()) {
            cout << "\n⚠️  No orders in the queue.\n";
        } else {
            cout << "\n📋 Current Orders in Queue: ";
            int i = front;
            while (true) {
                cout << "#" << queue[i] << " ";
                if (i == rear) break;
                i = (i + 1) % maxSize;
            }
            cout << "\n";
        }
    }

    ~PizzaParlor() {
        delete[] queue;
    }
};

int main() {
    int maxOrders, choice, orderID;
    cout << " Welcome to the Pizza Parlor Ordering System \n";
    cout << "Enter maximum number of orders the pizza parlor can accept: ";
    cin >> maxOrders;

    PizzaParlor parlor(maxOrders);

    do {
        cout << "\n------ Menu ------\n";
        cout << "1. Place Order\n2. Serve Order\n3. Display Orders\n4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Order ID to place: ";
                cin >> orderID;
                parlor.placeOrder(orderID);
                break;
            case 2:
                parlor.serveOrder();
                break;
            case 3:
                parlor.displayOrders();
                break;
            case 4:
                cout << " Exiting the system. Thank you!\n";
                break;
            default:
                cout << " Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
