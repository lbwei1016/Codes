template<class T>
class Node {
    public:
        T data;
        Node *nxt;

        Node (): nxt(nullptr) {}
        Node (const T _data): data(_data) {}
};

template<class T>
class linkedQueue {
    public:
        linkedQueue(): _size(0) { 
            head = new Node<T>;
            tail = head;
            head->nxt = tail;
        }

        void push(const T &data) {
            Node<T> *tmp = new Node<T>(data);
            if (tail != nullptr)
                tail->nxt = tmp;
            tail = tmp;
            ++_size;
        }
        void pop() {
            if (_size == 0) return;
            Node<T> *tmp = head->nxt;
            delete head;
            head = tmp;
            --_size;
        }
        T front() const {
            return head->nxt->data;
        }
        int size() const {
            return this->_size;
        }
    private:
        int _size;
        Node<T> *head, *tail;
};

/*
#include <iostream>
#include "linked_queue.h"
using namespace std;

int main() {
    linkedQueue<int> que;
    for (int i=0; i<5; ++i) {
        que.push(i);
    }
    cout << "size: " << que.size() << '\n';
    for (int i=0; i<5; ++i) {
        cout << que.front() << ' ';
        que.pop();
    }
    return 0;
}
*/