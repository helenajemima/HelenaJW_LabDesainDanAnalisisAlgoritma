#include <iostream>
using namespace std;

struct Ticket {
    int number;
    string name; 
    Ticket *next;
};


class Queue {
private:
    Ticket *head;
    Ticket *tail;

public:
    Queue() {
        head = NULL;
        tail = NULL;
    }

	void newTicket(int num) {
	    string Name;
	    cout << "\nEnter Customer Name: ";
	    cin >> Name;
	
	    Ticket *ticketNode = new Ticket();
	    ticketNode->number = num;
	    ticketNode->name = Name; // Store customer name
	    ticketNode->next = NULL;
	
	    if (tail == NULL) {
	        head = ticketNode;
	        tail = ticketNode;
	    } else {
	        tail->next = ticketNode;
	        tail = ticketNode;
	    }
	
	    cout << "\nTicket for " << ticketNode->name << " issued!\n";
	}


    void serve() {
        if (head == NULL) {
            cout << "\nNo tickets in the queue!" << endl;
        } else {
            Ticket *temp = head;
            cout << "\nServing ticket " << temp->number << endl;
            head = head->next;
            delete temp;
            if (head == NULL) {
                tail = NULL; 
            }
        }
    }

	void display() {
	    if (head == NULL) {
	        cout << "\nTicket Queue is empty\n" << endl;
	    } else {
	        cout << "\nTicket Queue: \n";
	        Ticket *current = head;
	        while (current != NULL) {
	            cout << "Ticket " << current->number << " - Customer: " << current->name << endl;
	            current = current->next;
	        }
	    }
	}

    bool isEmpty() {
        return head == NULL;
    }

    void clear() {
        Ticket *current = head;
        while (current != NULL) {
            Ticket *temp = current;
            current = current->next;
            delete temp;
        }
        head = NULL;
        tail = NULL;
        cout << "\nTicket queue has been cleared.\n" << endl;
    }
};

int main() {
    Queue ticketQueue;
    char choice;
    int num = 1;

    while (true) {
        cout << "\nLOCKET TICKET QUEUE" << endl;
        cout << "1. Get New Ticket" << endl;
        cout << "2. Serve Next Ticket" << endl;
        cout << "3. Display Ticket Queue" << endl;
        cout << "4. Exit System" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case '1':
                ticketQueue.newTicket(num);
                num++;
                break;
            case '2':
                ticketQueue.serve();
                break;
            case '3':
                ticketQueue.display();
                break;
            case '4':
                cout << "Exiting the system." << endl;
                return 0;
            default:
                cout << "Invalid input." << endl;
                break;
        }
    }
}

