/*
    Reference: https://openhome.cc/Gossip/CppGossip/sharedPtr.html
*/
template<typename T>
class SharedPtr {
private:
    /*
        Deleter 是自訂的共享刪除器，這裡並沒有定義，因此
        destructor 使用的依然是 "delete"。
    */
    using Deleter = void (*)(T*); 

    T* ptr = nullptr;
    size_t *cnt = nullptr; // reference count: 有多少 ptr 指向該 memory
    Deleter del = nullptr; // deleter

    // 賦值給 this 的功能 (this 不能被 assign, i.e. "this = X" 不合法)
    void swap(SharedPtr &shrPtr) {
        std::swap(this->p, shrPtr.ptr);
        std::swap(this->cnt, shrPtr.cnt);
        std::swap(this->del, shrPtr.del);
    }

public:
    // default constructor
    SharedPtr(T *_ptr = nullptr, Deleter _del = nullptr):
        ptr(_ptr), cnt(new size_t(_ptr != nullptr)), del(_del) {}
    
    // copy constructor
    SharedPtr(const SharedPtr &shrPtr): 
        ptr(shrPtr.ptr), cnt(shrPtr.cnt), del(shrPtr.del) {
            ++(*(this->cnt)); // reference count +1
        }

    // rvalue-reference constructor (通常是為了效率上的考量)
    // call "SharedPtr()" (the top-most constructor) first
    SharedPtr(SharedPtr &&shrPtr): SharedPtr() {
        this->swap(shrPtr);
    }

    // 參數不是 reference，因為不該被更動
    // shrPtr 參數在執行過後就摧毀了，參考計數會減一
    SharedPtr& operator=(SharedPtr shrPtr) {
        this->swap(shrPtr);
        return *this;
    }

    ~SharedPtr() {
        if (this->ptr == nullptr) return;
        // 若 reference count 為零，刪除資源
        if (--(*(this->cnt)) == 0) {
            // 若 Deleter 有被定義，則使用 Deleter，否則就 "delete"
            this->del ? this->del(this->ptr) : delete this->ptr;
            delete cnt;
        }
    }

    // 將 this "reset" 成傳入參數的樣子
    void reset(T *ptr = nullptr, Deleter del = nullptr) {
        // wrapper 參數在執行過後就摧毀了，參考計數會減一
        SharedPtr wrapper(ptr, del);
        this->swap(wrapper);
    }

    // return "reference count"
    size_t use_count() { return *(this->cnt); } 

    // 令 SharedPtr 行為像個指標
    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }
};