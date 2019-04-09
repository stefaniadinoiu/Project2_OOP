#include <iostream>
#include "LinkedList.h"
#include "Coada.h"
#include "Deque.h"
#include "PriorityQueue.h"
#include <cstdio>
#include <cstdlib>

using namespace std;


void Project()
{
    cout << "----------- PROJECT II. SUBJECT 3 ----------\n";
    cout << "----------- DINOIU NADIA STEFANIA ---------\n";
    cout << "------------------ GROUP 211 --------------\n";
}

void Menu_QUEUE_TYPE_choice()
{
    cout << "1. Normal Queue\n";
    cout << "2. Dequeue\n";
    cout << "3. Priority Queue\n";
}

void Menu_QUEUE_Operations()
{
    cout << "1. PUSH elements into the queue\n";
    cout << "2. POP elements from the queue\n";
    cout << "3. Display the TOP of the queue\n";
    cout << "4. SUM of two queues\n";
    cout << "5. DIFFERENCE between 2 \n";
    cout << "0. EXIT\n";
}



int main()
{
    int n, qType;
    Coada sum;
    Coada dif;
    Project();

    cout << "The number of queues you want to enter :  ";
    cin >> n;

    Coada **arr = new Coada*[n];

    for (int i = 0; i < n; ++i)
    {
        cout << "\nQueue type : \n";

        Menu_QUEUE_TYPE_choice();

        cin >> qType;

        switch (qType)
        {
        case 1:
        {
            Coada *q = new Coada();
            int option2;

            cout << "\nChoose Queue operation: ";
            Menu_QUEUE_Operations();

            cin >> option2;

            while(option2)
            {
                switch(option2)
                {
                case 0:
                    break;
                case 1:
                {
                    cout << "\nPress ENTER to stop introducing elements: \n ";
                    cin >> *q;
                    arr[i] = q;

                    cout << "\nQueue is: ";

                    cout << *arr[i] << '\n';

                    break;
                }

                case 2:
                {

                    q->pop();
                    arr[i] = q;
                    cout << "\nRemained items: ";

                    cout << *arr[i] << '\n';
                    break;
                }
                case 3:
                {
                    cout << "\nThe TOP of the queue is: ";
                    cout << q->topp();
                    break;
                }
                case 4:
                    sum = sum +  *q;
                    cout << "\nSUM is: " << sum;
                    break;
                case 5:
                    dif = *q - dif;
                    cout << "\nDIFFERENCE is: " << dif;
                    break;

                }

                cout << "\nChoose Queue operation: ";

                Menu_QUEUE_Operations();

                cin >> option2;
            }

        }
        break;
        case 2:
        {
            Deque *q = new Deque();
            int option2;

            cout << "\nChoose Queue operation: ";
            Menu_QUEUE_Operations();

            cin >> option2;

            while(option2)
            {
                switch(option2)
                {
                case 0:
                    break;

                case 1:
                {
                    cout << "Press ENTER to stop introducing elements: \n";
                    cin >> *q;
                    arr[i] = q;

                    cout << "\nQueue is: ";

                    Deque *d = dynamic_cast<Deque*>(arr[i]);
                    if (d)
                        cout << *d << '\n';
                    break;
                }

                case 2:
                {
                    q -> pop_back();
                    q -> pop_front();

                    arr[i] = q;

                    cout << "\nRemained items: ";

                    Deque *d = dynamic_cast<Deque*>(arr[i]);
                    if (d)
                        cout << *d << '\n';
                    break;

                }

                case 3:
                {
                    cout << "\nTOP_FRONT of the Dequeue is: ";
                    cout << q -> topp();
                    break;
                }
                case 4:
                    sum = sum + *q;
                    cout << "\n SUM is: " << sum;
                    break;
                case 5:
                {
                    Coada *aux = q;
                    dif = *aux - dif;
                    cout << "\n DIFFERENCE is: " << dif;
                    break;
                }

                }

                cout << "\nChoose Queue operation: ";

                Menu_QUEUE_Operations();

                cin >> option2;
            }
        }
        break;
        case 3:
        {
            PriorityQueue *q = new PriorityQueue();
            int option2;

            cout << "\nChoose Queue operation: ";
            Menu_QUEUE_Operations();

            cin >> option2;

            while(option2)
            {
                switch(option2)
                {
                case 0:
                    break;
                case 1:
                {
                    cout << " Press ENTER to stop introducing elements: \n";
                    cin >> *q;
                    arr[i] = q;

                    cout << "\nQueue is: ";

                    PriorityQueue *p = dynamic_cast<PriorityQueue*>(arr[i]);
                    if (p)
                        cout << *p << '\n';
                    break;

                }

                case 2:
                {
                    q -> pop();

                    arr[i] = q;

                    cout << "\nRemained items ";

                    PriorityQueue *p = dynamic_cast<PriorityQueue*>(arr[i]);
                    if (p)
                        cout << *p << '\n';
                    break;
                }

                case 3:
                {
                    cout << "\nTOP of the Priority Queue is: ";
                    cout << q -> topp();

                    break;
                }

                case 4:
                    sum = sum + *q;
                    cout << "\nSUM is: " << sum;
                    break;
                case 5:
                {
                    Coada *aux = q;
                    dif = *aux - dif;
                    cout << "\n DIFFERENCE is: " << dif;
                    break;
                }
                }

                cout << "\nChoose Queue operation: ";

                Menu_QUEUE_Operations();

                cin >> option2;
            }
        }
        break;

        }

        /*cout << "Queue type : \n";

        Menu_QUEUE_TYPE_choice();

        cin >> qType;*/
    }

    for(int i = 0; i < n; i++)
    {
        delete arr[i];
    }


    return 0;

}
