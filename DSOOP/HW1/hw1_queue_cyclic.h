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
class Queue: public Bag<T> {
    public:
        Queue(int queueCapacity = 10) {
            this->capacity = queueCapacity;
            this->array = new T[queueCapacity];
            this->top = this->tail = size = 0;
        }
        ~Queue() { delete[] this->array; }

        int Size() { return size; }
        bool IsEmpty() { return size == 0; }
        int Capacity() { return this->capacity; }

        // return "front" element in queue
        T Element() const {
            return this->array[this->top % this->capacity];
        }
        
        // push an element at the end of queue
        void Push(const T var) {
            this->top %= this->capacity;
            this->tail %= this->capacity;

            // cyclic
            if (this->tail == this->top) {
                // full 
                if (size == this->capacity) {
                    this->capacity = (this->capacity + 1) * 2;
                    T *new_block = new T[this->capacity];
                    memcpy(new_block, this->array + this->top, sizeof(T)*(size));
                    delete this->array;

                    this->array = new_block;
                    this->tail = size;
                    this->top = 0;
                }
            }
            this->array[(this->tail)++] = var;
            ++size;
        }
        void Pop() {
            if (IsEmpty()) return; 
            this->top %= this->capacity;
            ++(this->top);
            --size;
        }
    private:
        int size; // number of elements
};