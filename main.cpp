#include <iostream>

using namespace std;
template <typename T> class Node{
    public:
        T data;
        Node * next;
        Node(T data, Node* next)
        {
            this->data = data;
            this->next = next;
        }
};

template <typename T> class LinkedList{
    public:
        Node<T> *Head = NULL;
        void Insert(T data)
        {
            Node<T> *New_node = new Node<T>(data,NULL);
            New_node->next = this->Head;
            this->Head = New_node;
        }

        void Insert(T data, int index)
        {
            if(index == 0)
                this->Insert(data);
        }

        void display()
        {
            Node<int> *itr_node = this->Head;
            while(itr_node != NULL)
                {
                    cout<<itr_node->data<<endl;
                    itr_node = itr_node->next;
                }
        }

};
int main()
{
    LinkedList<int> ls;

    ls.Insert(10);
    ls.Insert(11);
    ls.Insert(12);
    ls.Insert(13);

    ls.display();
    return 0;
}
