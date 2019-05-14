/*
Nama        : Falah Rizqi Abudllah Fairuz
NPM         : 140810180069
Deskripsi   : exercise-02 queue linked list
Kelas       : A
*/

#include<iostream>
using namespace std;

struct ElemenQueue
{
    char info;
    ElemenQueue* next;
};

typedef ElemenQueue* pointer;
typedef pointer List;

struct Queue
{
    List Head;
    List Tail;
};

void createList(Queue& Q)
{
	Q.Head = NULL;
    Q.Tail = NULL;
}

void createElemt(pointer& pBaru)
{
	pBaru = new ElemenQueue;
	cout << "Input : ";
	cin >> pBaru->info;
	pBaru->next = NULL;
}

void cetak(Queue Q)
{
    pointer pBantu = Q.Head;
    if(Q.Head == NULL && Q.Tail == NULL)
    {
        cout << "Empty List" << endl;
    }
    else
    {
        while(pBantu != NULL)
        {
            cout << pBantu->info << " ";
            pBantu = pBantu->next;
        }
    }
}

void traversal(List First)
{
	pointer pBantu;
	if(First==NULL)
    {
		cout << "List kosong"<<endl;
	}
	else
    {
		pBantu = First;
		do
        {
			cout << pBantu->info;
			pBantu = pBantu->next;
		} while(pBantu != NULL);
	}
}

void insertQueue( Queue& Q, pointer pBaru)
{
    if (Q.Head == NULL && Q.Tail == NULL) { 
        Q.Head = pBaru;
        Q.Tail = pBaru;
    }
    else
    { 
        Q.Tail->next = pBaru;
        Q.Tail = pBaru;
    }
}

void deleteQueue(Queue& Q, pointer& pHapus)
{
    if (Q.Head == NULL && Q.Tail == NULL)
    { 
        pHapus = NULL;
        cout << "Empty Lsit" << endl;
    }
    else if (Q.Head->next==NULL)
    { 
        pHapus = Q.Head;
        Q.Head = NULL;
        Q.Tail = NULL;
    }
    else
    { 
        pHapus = Q.Head;
        Q.Head = Q.Head->next;
        pHapus->next = NULL;
    }
}

main()
{
    Queue Q;
    pointer p;
    List l;
    int n;

    createList(Q);
    cout << "Banyak elemen : "; cin >> n;
    for(int i = 0; i < n; i++)
    {
        createElemt(p);
        insertQueue(Q,p);
    }
    cout << "Queue : " << endl;
    cetak(Q);
    cout<<endl;

    deleteQueue(Q,p);
    cout << "Queue[After Delete] : " << endl;
    cetak(Q);
    cout<<endl;
}
