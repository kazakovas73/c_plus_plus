#include <iostream>

using namespace std;

class Matrix {
private:
    const int dim = 2;
    int matrix[dim*dim];

public:
    Matrix () {
        //matrix = new int[dim * 2];
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                matrix[j + dim * i] = 0;
            }
        }
    }
    Matrix(int a_00, int a_01, int a_10, int a_11) {
        this->matrix[0] = a_00;
        this->matrix[1] = a_01;
        this->matrix[2] = a_10;
        this->matrix[3] = a_11;
    }
    Matrix(const Matrix& m) {
        //matrix = new int[dim * 2];
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                matrix[j + dim * i] = m.matrix[j + dim * i];
            }
        }
        cout << "Конструктор копирования\n";
    }
    ~Matrix() {
        //delete matrix;
        cout << "Matrix is deleted\n";
    }
    Matrix& operator+=(const Matrix& m) {
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                this->matrix[j + dim * i] += m.matrix[j + dim * i];
            }
        }
        return *this;
    }

    Matrix& operator-=(const Matrix& m) {
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                this->matrix[j + dim * i] -= m.matrix[j + dim * i];
            }
        }
        return *this;
    }

    Matrix& operator=(const Matrix& m) {
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                this->matrix[j + dim * i] = m.matrix[j + dim * i];
            }
        }
        return *this;
    }

    Matrix operator*(int num) {
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                    this->matrix[j + 2 * i] *= num;
            }
        }
        return *this;
    }

    Matrix operator*(const Matrix& m) {
        Matrix m_res;
        /*for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                for (int k = 0; k < dim; k++) {
                    m_res.matrix[j + 2 * i] += this->matrix[k + 2 * i] * m.matrix[j + 2 * k];
                }
            }
        }*/
        m_res.matrix[0] = this->matrix[0] * m.matrix[0] + this->matrix[2] * m.matrix[1];
        m_res.matrix[1] = this->matrix[1] * m.matrix[0] + this->matrix[3] * m.matrix[1];
        m_res.matrix[2] = this->matrix[0] * m.matrix[2] + this->matrix[2] * m.matrix[3];
        m_res.matrix[3] = this->matrix[1] * m.matrix[2] + this->matrix[3] * m.matrix[3];
        return m_res;
    }

    friend ostream& operator<<(ostream& os, Matrix& m);
    friend istream& operator>>(istream& is, Matrix& m);
};

ostream& operator<<(ostream& os, Matrix& m) {
    os << "Matrix:\n";
    for (int i = 0; i < m.dim; i++) {
        for (int j = 0; j < m.dim; j++) {
            os << m.matrix[j + 2 * i] << " ";
        }
        os << "\n";
    }

    return os;
}

istream& operator>>(istream& is, Matrix& m) {
    cout << "Input matrix: \n";

    for (int i = 0; i < m.dim; i++) {
        for (int j = 0; j < m.dim; j++) {
            cout << "element[" << i << "][" << j << "] : ";
            is >> m.matrix[j + 2 * i];
        }
    }
    return is;
}

Matrix operator+(const Matrix& m1, const Matrix& m2) {
    Matrix m3(m1);
    m3 += m2;
    return m3;
}
Matrix operator-(const Matrix& m1, const Matrix& m2) {
    Matrix m3(m1);
    m3 -= m2;
    return m3;
}

int main() {

    Matrix m1;
    Matrix m2 = m1;
    Matrix m3;
    cin >> m1;
    //cout << m1;
    cin >> m2;
    m3 = m1 * m2;
    cout << m3;

    return 0;
}
