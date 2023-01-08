namespace my_imp {
    class queue {
        public:
            queue(const int &sz): sz(sz) {}
            ~queue() { delete [] que; }
            void resize(const int &sz);
            void push(const int &val);
            void pop();
            int size() const;
            bool empty() const;
         private:
            int *que;
            int sz, capacity;
            int front, rear;
            void data_transfer(const int &sz);
    };
}
