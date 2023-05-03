/*
    Shared Pointer for CP
*/
template<typename T>
class SharedPtr {
private:
    T* ptr = nullptr;
    size_t *cnt = nullptr; // reference count: 有多少 ptr 指向該 memory

    void swap(SharedPtr &shrPtr) {
        std::swap(this->p, shrPtr.ptr);
        std::swap(this->cnt, shrPtr.cnt);
    }

public:
    SharedPtr(T *_ptr = nullptr):
        ptr(_ptr), cnt(new size_t(_ptr != nullptr)) {} 

    SharedPtr(const SharedPtr &shrPtr): 
        ptr(shrPtr.ptr), cnt(shrPtr.cnt) {
            ++(*(this->cnt)); // reference count +1
        }

    SharedPtr& operator=(SharedPtr shrPtr) {
        this->swap(shrPtr);
        return *this;
    }

    ~SharedPtr() {
        if (this->ptr == nullptr) return;
        if (--(*(this->cnt)) == 0) {
            delete this->ptr;
            delete cnt;
        }
    }

    size_t use_count() { return *(this->cnt); } 

    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }
};