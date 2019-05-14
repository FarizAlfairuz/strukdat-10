/*
Nama        : Falah Rizqi Abudllah Fairuz
NPM         : 140810180069
Deskripsi   : exercise-01 queue array
Kelas       : A
*/

#include<iostream>
using namespace std;

const int maxElemen = 255;

struct Queue
{
    char isi[maxElemen];
    int head;
    int tail;
};

void createQueue (Queue& Q)
{
    Q.head = 0;
    Q.tail = -1;
}

void insertQueue(Queue& Q, char elemen)
{
    if (Q.tail == maxElemen-1)
    {
        cout << "Queue Full" << endl;
    }
    else
    {
        Q.tail = Q.tail + 1;
        Q.isi[Q.tail] = elemen;
    }
}

void deleteQueue(Queue& Q, char& elemenHapus)
{
    if (Q.head > Q.tail)
    {
        cout << "Empty Queue" << endl;
    }
    else
    {
        elemenHapus= Q.isi[Q.head];
        for (int i = 0; i < Q.tail; i++)
        {
            Q.isi[i] = Q.isi[i+1];
        }
        Q.tail = Q.tail-1;
    }
}

main()
{
    char a;
    Queue Q;
    int n;

    createQueue(Q);

    cout << "Panjang Antrian : "; cin >> n;
    for(int i = 0; i < n; i++)
    {
        cout << "Input Data : "; cin >> a;
        insertQueue(Q,a);
    }
    cout << "Queue : " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << Q.isi[i] << ",";
    }
    cout << endl;

    deleteQueue(Q,a);
    cout << "Queue[After Delete] : " << endl;
    for(int i = 0; i < n-1; i++)
    {
        cout << Q.isi[i] << ",";
    }
    cout << endl;
}