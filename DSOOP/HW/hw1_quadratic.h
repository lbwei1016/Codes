class Quadratic {
    public:
        int a, b, c;
        Quadratic(const int &_a, const int &_b, const int &_c) {
            a = _a;
            b = _b;
            c = _c;
        }
        Quadratic operator+(const Quadratic &q) {
            return Quadratic(a+q.a, b+q.b, c+q.c);
        }
};