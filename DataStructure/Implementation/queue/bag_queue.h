#ifndef _CSTRING_
#define _CSTRING_
#include <cstring>
#endif

// "Bag" is a "class template"; "Bag<int>" is a "class"
// abstract class
template<typename T>
class Bag {
    public:
        Bag() {}
        virtual ~Bag() = default;

        virtual int Size() { return tail - top; }
        virtual bool IsEmpty() { return tail == top; }
        // virtual func() = 0; => pure virtual function
        virtual T Element() const = 0;

        virtual void Push(const T) = 0;
        virtual void Pop() = 0;

    protected:
        T *array; // stores elements
        int capacity; // the maximum number can be used to store elements, without reallocation
        int top; // array position of top element
        int tail; // array position of tail element
};

template<typename T>
// pubilcly inheritance (check "./inheritance_modifier.png")
class Queue: public Bag<T> {
    public:
        Queue(int queueCapacity = 10) {
            this->capacity = queueCapacity;
            this->array = new T[queueCapacity];
            this->top = this->tail = 0;
        }
        ~Queue() { delete[] this->array; }

        // return "front" element in queue
        T Element() const {
            // out of range access cause undefined behavior
            return this->array[this->top];
        }
        
        // push an element at the end of queue
        void Push(const T var) {
            // out of capacity
            if (this->tail == this->capacity) {
                this->capacity *= 2;
                T *tmp = new T[this->capacity];
                memcpy(tmp, this->array + this->top, sizeof(T)*(this->tail - this->top));
                delete this->array;

                this->array = tmp;
                this->tail -= this->top;
                this->top = 0;
            }
            this->array[this->tail++] = var;
        }
        void Pop() {
            if (this->IsEmpty()) return; 
            ++(this->top);
        }
};
