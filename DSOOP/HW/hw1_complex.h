class Complex {
    public:
        int real, img;
        Complex(): real(0), img(0) {};
        Complex(const int &_r, const int &_i): real(_r), img(_i) {};
};