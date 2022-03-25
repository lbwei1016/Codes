class Entry {
    public:
        int row, col, val;
};
class SparseMatrix {
    public:
        int size;
        Entry *entries;
        SparseMatrix(SparseMatrix &_M) {
            entries = new Entry[_M.size];
            for (int i=0; i<_M.size; ++i) {
                entries[i] = _M.entries[i];
            }
        }
};