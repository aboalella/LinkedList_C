#include <iostream>

using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node *next;
    Node(T data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
    Node()
    {
        this->next = NULL;
    }
};

template <typename T>
class LinkedList
{
public:
    Node<T> *Head = NULL;
    void Insert(T data)
    {
        Node<T> *New_node = new Node<T>(data, NULL);
        New_node->next = this->Head;
        this->Head = New_node;
    }

    void Insert(T data, int index)
    {
        if (index == 0)
            this->Insert(data);
        else
        {
            Node<T> *itr = this->Head;
            for (int i = 1; i < index; i++)
                itr = itr->next;
            Node<T> *new_node = new Node<T>(data, NULL);
            new_node->next = itr->next;
            itr->next = new_node;
        }
    }

    void Remove()
    {
        Node<T> *removed_node = this->Head;
        this->Head = this->Head->next;
        delete removed_node;
    }

    void Remove(int index)
    {
        if (index == 0)
            this->Remove();
        else
        {

            Node<T> *removed_node = this->Head;
            Node<T> *previous_node = this->Head;
            for (int i = 0; i < index; i++)
            {
                previous_node = removed_node;
                removed_node = removed_node->next;
            }
            previous_node->next = removed_node->next;
            delete removed_node;
        }
    }
    void display()
    {
        Node<int> *itr_node = this->Head;
        int i = -1;
        while (itr_node != NULL)
        {
            i++;
            cout << "Node_" << i << " = " << itr_node->data << endl;
            itr_node = itr_node->next;
        }
    }
};
int main()
{
    LinkedList<int> ls;

    ls.Insert(10);
    ls.Insert(11, 1);
    ls.Insert(12, 2);
    ls.Insert(14, 3);
    ls.Insert(13, 3);

    ls.Remove();
    ls.display();

    ls.Remove(1);
    ls.display();
    return 0;
}
