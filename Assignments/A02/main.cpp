/**
     *  Course: CMPS 2143 - OOP
     *
     *  Purpose: concatanate lists
     * 
     *  @author Daniel Daycee Duncan
     *  @version 1.1 09/04/18 
     */

#include <iostream>

using namespace std;

int A[100];

//Object created to store integers
struct Node
{
    int x;
    Node *next;
    Node()
    {
        x = -1;
        next = NULL;
    }
    Node(int n)
    {
        x = n;
        next = NULL;
    }
};

//provides methods to main.cpp to create and concatanate lists
class List
{
  private:
    Node *Head;
    Node *Tail;
    int Size;

  public:
    //creates an empty list
    List()
    {
        Head = Tail = NULL;
        Size = 0;
    }
    
    // adds nodes to the front of the list
    void Push(int val)
    {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        if (!Head && !Tail)
        {
            Head = Tail = Temp;
        }
        else
        {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }

    //adds nodes to the end of the list
    void Insert(int val)
    {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        // figure out where it goes in the list

        Temp->next = Head;
        Head = Temp;
        if (!Tail)
        {
            Tail = Head;
        }
        Size++;
    }

    //prints the last value of list
    void PrintTail()
    {
        cout << Tail->x << endl;
    }

    //prints entire list
    string Print()
    {
        Node *Temp = Head;
        string list;

        while (Temp != NULL)
        {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }

    // not implemented 
    int Pop()
    {
        Size--;
        return 0; //
    }

    List operator+(const List &Rhs)
    {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

    // Implementation of [] operator.  This function returns an
    // int value as if the list were an array.
    int operator[](int index)
    {
        Node *Temp = Head;

        if (index >= Size)
        {
            cout << "Index out of bounds, exiting";
            exit(0);
        }
        else
        {

            for (int i = 0; i < index; i++)
            {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }

    friend ostream &operator<<(ostream &os, List L)
    {
        os << L.Print();
        return os;
    }
};

int main(int argc, char **argv)
{
    //creates lists
    List L1;
    List L2;

    //fills list L1
    for (int i = 0; i < 25; i++)
    {
        L1.Push(i);
    }

    //fills list L2
    for (int i = 50; i < 100; i++)
    {
        L2.Push(i);
    }

    //cout << L1 << endl;
    L1.PrintTail();
    L2.PrintTail();

    //concatanates lists
    List L3 = L1 + L2;
    cout << L3 << endl;

    //prints value of L3 at location 5 of the list
    cout << L3[5] << endl;
    return 0;
}
