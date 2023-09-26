// Porter_AdvAlg_Midterm.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>

//extra
#include "Define.h"
#include "Util.h";
//#include "Queue.h" needed for initial queue testing 
#include "GameServer.h" //contains our PlayerQueue and our List vector 
#include "PriorityHeap.h"
#include "AccountHeap.h"
#include "Timer.cpp"

using namespace std;

//output prompts
void ControlPrompt()
{
    cout << "\nControl Menu\n";
    cout << "1. Log Account(s)" << endl;
    cout << "2. Queue Account Player(s)" << endl;
    cout << "3. GameServer Disconnects" << endl;
    cout << "4. System (continuously cycles - fresh run to avoid inconsistencies - recommended)" << endl;
}
void LoginPrompt() 
{
    cout << "\nLogin Menu\n";
    cout << "1. Login 1 Account" << endl;
    cout << "2. Login 5 Accounts" << endl;
    cout << "3. Login ALL Accounts in Heap (will pass entire HEAP into the other structures)" << endl;
    cout << "4. Back" << endl;
}
void QueuePrompt()
{
    cout << "\nQueue Menu\n";
    cout << "1. Enqueue 1 Account Player" << endl;
    cout << "2. Enqueue 5 Account Players" << endl;
    cout << "3. Enqueue ALL available" << endl;
    cout << "4. Dequeue 1 Account Player" << endl;
    cout << "5. Dequeue 5 Account Players" << endl;
    cout << "6. Dequeue ALL available" << endl;
    cout << "7. Back" << endl;
}
void GameServerPrompt()
{
    cout << "\nServer Menu\n";
    cout << "1. Kick 1 Player Offline" << endl;
    cout << "2. Kick 5 Players Offline" << endl;
    cout << "3. Back" << endl;
}

int main()
{
    //simulation timers -> would not really be need in real use
    Timer loginTimer;
    Timer queueTimer;
    Timer serverTimer;
    Timer bootTimer;

    //Construct our heap object
    AccountHeap heap;
    heap.Heap.resize(HEAP_SIZE);
    heap.FillAccountHeap();

    //Construct player queue and capacity allowance
    PlayerQueue* pq = new PlayerQueue();
    pq = pq->constructQueue(QUEUE_CAPACITY);

    //Construct GameServer object that contains our player list
    GameServer server;
    server.SetMaxCapacity(GAMESERVER_CAPACITY);


    //This is a big blob of Switch statements for Menu Control, each piece is really just a generic set of calls used within loops for length
    int reply = -1;
    while (reply != 5)
    {
        ControlPrompt();
        cin >> reply;
        int menu = -1;
        
        switch (reply)
        {
            case 1: //LOGIN MENU
                while (menu != 4)
                {
                    LoginPrompt();
                    cin >> menu;
                    system("cls");
                    switch (menu)
                    {

                    case 1:                     //Log 1 account
                        if (!heap.IsEmpty() && !server.IsServerFull())
                        {
                            server.AddPlayerToServer(heap.ExtractMaxPrio().character);
                        }
                        else if (!heap.IsEmpty())
                        {
                            pq->Enqueue(pq, heap.ExtractMaxPrio().character);
                        }
                        /*else if (heap.IsEmpty())
                        {
                            cout << "\nHeap has been depleted, no more entries.";
                        }*/
                        break;
                    case 2:                     //Log 5 Accounts
                        for (int i = 0; i < 5; i++)
                        {
                            if (!heap.IsEmpty() && !server.IsServerFull())
                            {
                                server.AddPlayerToServer(heap.ExtractMaxPrio().character);
                            }
                            else if (!heap.IsEmpty())
                            {
                                pq->Enqueue(pq, heap.ExtractMaxPrio().character);
                            }
                            else if (heap.IsEmpty())
                            {
                                cout << "\nHeap has been depleted, no more entries.";
                            }
                        }
                        break;
                    case 3:                         //Log ALL accounts til empty
                        for (int i = 0; i < heap.Heap.size(); i++)
                        {
                            if (!heap.IsEmpty() && !server.IsServerFull())
                            {
                                server.AddPlayerToServer(heap.ExtractMaxPrio().character);
                            }
                            else if (!heap.IsEmpty())
                            {
                                pq->Enqueue(pq, heap.ExtractMaxPrio().character);
                            }
                            /*else if (heap.IsEmpty())
                            {
                                cout << "\nHeap has been depleted, no more entries.";
                            }*/
                        }
                        break;
                    }
                }
                break;
            case 2: //QUEUE MENU
                while (menu != 7)
                {
                    QueuePrompt();
                    cin >> menu;
                    system("cls");
                    switch (menu)
                    {
                    case 1:                //Log 1 account player
                        if (!heap.IsEmpty() && !server.IsServerFull())
                        {
                            cout << "\nGameServer is not yet full, adding player to GameServer!";
                            server.AddPlayerToServer(heap.ExtractMaxPrio().character);
                        }
                        else if (!heap.IsEmpty() && server.IsServerFull())
                        {
                            pq->Enqueue(pq, heap.ExtractMaxPrio().character);
                        }
                        else if (heap.IsEmpty())
                        {
                            cout << "\nHeap has been depleted, no more entries.";
                        }
                        break;
                    case 2:                //Queue 5 Accounts Players
                        for (int i = 0; i < 5; i++)
                        {
                            if (!heap.IsEmpty() && !server.IsServerFull())
                            {
                                cout << "\nGameServer is not yet full, adding player to GameServer!";
                                server.AddPlayerToServer(heap.ExtractMaxPrio().character);
                            }
                            else if (!heap.IsEmpty() && server.IsServerFull())
                            {
                                pq->Enqueue(pq, heap.ExtractMaxPrio().character);
                            }
                            else if (heap.IsEmpty())
                            {
                                cout << "\nHeap has been depleted, no more entries.";
                            }
                        }
                        break;
                    case 3:                //Log ALL accounts players til empty
                        for (int i = 0; i < heap.Heap.size(); i++)
                        {
                            if (!heap.IsEmpty() && !server.IsServerFull())
                            {
                                cout << "\nGameServer is not yet full, adding player to GameServer!";
                                server.AddPlayerToServer(heap.ExtractMaxPrio().character);
                            }
                            else if (!heap.IsEmpty() && server.IsServerFull())
                            {
                                pq->Enqueue(pq, heap.ExtractMaxPrio().character);
                            }
                            else if (heap.IsEmpty())
                            {
                                cout << "\nHeap has been depleted, no more entries.";
                            }
                        }
                        break;
                    case 4:
                        if(!server.IsServerFull())
                            pq->Dequeue(pq);
                        else {
                            cout << "\nServer is full.";
                        }
                        break;
                    case 5:
                        for (int i = 0; i < 5; i++)
                        {
                            if (!server.IsServerFull())
                                pq->Dequeue(pq);
                            else {
                                cout << "\nServer is full.";
                            }
                        }
                        break;
                    case 6:
                        for (int i = 0; i < pq->size; i++)
                        {
                            if (!server.IsServerFull())
                                pq->Dequeue(pq);
                            else {
                                cout << "\nServer is full.";
                            }
                        }
                        break;
                    }
                }
                break;
            case 3: //GAMESERVER MENU
                while (menu != 3)
                {
                    GameServerPrompt();
                    cin >> menu;
                    system("cls");
                    switch (menu)
                    {
                    case 1:
                        if (!server.IsServerEmpty())
                        {
                            server.RandomDisconnect(pq, 1);
                        }
                        break;
                    case 2:
                        if (!server.IsServerEmpty())
                        {
                            server.RandomDisconnect(pq, 5);
                        }
                        break;
                    }
                }

                break;
            case 4: //COUNTINUOUS SYSTEM -> RECOMMENDED USE CASE AS ITS CONTROL IS FULLY AUTOMATED
            int runner = -1;

            cout << "\nHeap Capacity: " + HEAP_SIZE;
            cout << "\tQueue Capacity: " << (pq->size) << " / " << pq->capacity;
            cout << "\tServer Capacity: " << server.GetCurCapacity() << " / " << server.playerList.size() << endl;
            while(runner == -1)
            {
                double logTime = loginTimer.elapsed();
                double queueTime = queueTimer.elapsed();
                double serverTime = serverTimer.elapsed();
                double disconnectTime = bootTimer.elapsed();
                if (logTime >= LOGIN_DELAY)
                {
                    if (!heap.IsEmpty() && !server.IsServerFull() && pq->IsEmpty(pq))
                    {
                        server.AddPlayerToServer(heap.ExtractMaxPrio().character);
                    }
                    loginTimer.reset();
                }
                if (queueTime >= DEQUEUE_DELAY)
                {

                    if (server.IsServerFull())
                    {
                        if (!heap.IsEmpty() && !pq->IsFull(pq))
                        {
                            pq->Enqueue(pq, heap.ExtractMaxPrio().character);
                        }
                    }
                    if (!server.IsServerFull())
                    {
                        if (!pq->IsEmpty(pq))
                        {
                            server.AddPlayerToServer(pq->Dequeue(pq));
                        }
                    }
                    server.AfkCheck(pq);
                    queueTimer.reset();
                }
                if (disconnectTime >= RANDOM_DISCONNECT_TIME)
                {
                    if (!server.IsServerEmpty())
                    {
                        server.RandomDisconnect(pq, heap.RandomRange(0, 3));
                    }
                    bootTimer.reset();
                }
                if (serverTime >= 2)
                {
                    for (int i = 0; i < server.playerList.size(); i++)
                    {
                        server.playerList[i]->m_TimeAfk += 2;
                    }
                    serverTimer.reset();
                }
            }
                break;
        }
    }
    
    /*
    //Initial Logins go into server if not full
    while (!server.IsServerFull())
    {
        server.AddPlayerToServer(heap.ExtractMaxPrio().character);
    }

    //while(server.IsServerFull() && !pq->IsFull(pq))
    {
        
            //pq->Enqueue(pq, heap.ExtractMaxPrio().character);
    }
    
    while(!server.IsServerFull() && !pq->IsEmpty(pq))
    {
    server.AddPlayerToServer(pq->Dequeue(pq));
    }
    */
    //initial queue testing prior to conversion
    /*
    Queue* queue = new Queue();
    queue = queue->constructQueue(5);
    queue->Enqueue(queue, 91);
    queue->Enqueue(queue, 22);
    cout << "\nBegin dequeue\n";
    queue->Dequeue(queue);
    queue->Dequeue(queue);
    */
    
    //Initial Setup
    //construct player queue
    /*
    PlayerQueue *pq = new PlayerQueue();    //this acts as the intermediary Queue that players will wait within to enter the game
    pq = pq->constructQueue(3);
    
    //construct gameserver;
    GameServer server;  //this acts as our List of players within the game
    server.SetMaxCapacity(3);
    server.SetCurCapacity(0);

    cout << "\nControl Menu\n";
    cout << "1. Login" << endl;
    cout << "2. Queue" << endl;
    cout << "3. GameServer" << endl;
    cout << "4. Combined Control Menu" << endl;

    
    //construct some temp players for testing 
    Player* p1 = new Player("West");
    Player* p2 = new Player("East");
    Player* p3 = new Player("North");
    Player* p4 = new Player("South");
    Player* p5 = new Player("Weast");
    Player* p6 = new Player("Reff Jeff");
    Player* p7 = new Player("Potatayo");

    //enqueue players
    pq->Enqueue(pq, p1);
    pq->Enqueue(pq, p2);
    pq->Enqueue(pq, p3);

    pq->Dequeue(pq);
    pq->Dequeue(pq);
    pq->Dequeue(pq);
    pq->Enqueue(pq, p4);
    pq->Enqueue(pq, p5);
    pq->Enqueue(pq, p6);
    pq->Enqueue(pq, p7);
    pq->FrontInfo();
    pq->BackInfo();
    pq->PrintQueue();
    pq->QueueInfo();

    //Initial Priority Heap testing, allows int variables to be ordered by max values, plan is to have Accounts object
    //accounts object holds a persons caches player character.  On login, Account passes the Player to the Queue or Gameserver.

    
    PriorityHeap heap;
    heap.SetHeapType(HeapType::minHeap);
    heap.Insert(1);
    heap.Insert(122);
    heap.Insert(14);
    heap.Insert(66);
    heap.Insert(646);

    heap.PrintHeap();
    int nextUp = heap.ExtractMaxPrio();
    heap.PrintHeap();

    Account tester = Account(0, "Luke");
    Account tester2 = Account(0, "Key");
    Player *t1 = new Player("Luke's Character");
    Player *t2 = new Player("Key's Character");
    tester.character = t1;
    tester2.character = t2;

    AccountHeap h;
    h.FillAccountHeap();

    h.PrintHeap();
    Account nextAcc = h.ExtractMaxPrio();
    h.PrintHeap();
    pq->Dequeue(pq);
    pq->Enqueue(pq,nextAcc.character);
    //dequeue players
    //if(!server.IsServerFull() && !pq->IsEmpty(pq))
    //{
      //  server.AddPlayerToServer(pq->Dequeue(pq));
    //}
    delete p1, p2, p3, p4, p5;
    */
}

