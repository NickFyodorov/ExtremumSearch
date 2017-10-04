class Function {
private:
    int dim;
public:
    Function(int _dim);
    virtual ~Function();
    virtual double eval() const = 0;
    int GetDim() const {
        return dim;
    }
};