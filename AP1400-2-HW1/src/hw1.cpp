#include "hw1.h"

namespace algebra{
    // zeros
    // implement this funciton so that it will create a n*m matrix with all elements equal to zero.
    // Create a matrix with n*m size and the elements are all equal zero.
    Matrix zeros(size_t n, size_t m){
        Matrix tmp{n,std::vector<double>{m,0.0}};
        return tmp;
    }
    // Create a matrix with n*m size and the elements are all equal one.
    Matrix ones(size_t n, size_t m){
        Matrix tmp{n,std::vector<double>{m,1.0}};
        return tmp;
    }
    // Create a matrix with n*m size and the value of the elements betweent the min and max.
    Matrix random(size_t n, size_t m, double min, double max){
        std::default_random_engine engine(std::random_device{}());    
        std::uniform_int_distribution<double> distribution(min,max);

        Matrix tmp{n,std::vector<double>{m}};
        for(const auto& row : tmp){
            for(const auto& elements : row){
                elements = distribution(engine);
            }
        }
        return random;
    }
    //implement this function so that it will display the matrix in a beautiful way.
    void show(const Matrix& matrix){
        std::cout << std::fixed << std::setprecision(3);

        for(const auto& row : tmp){
            for(const auto& elements : row){
                std::cout << std::setw(8) << elements << std::endl;
            }
        }
    }
    // -scalar number
    // implement this function so that it multiplies the matrix1 into the constant scalar c.
    Matrix multiply(const Matrix& matrix, double c){
        Matrix ret(matrix.size(),std::vector<double>(matrix[0].size()));
        for(size_t i = 0; i < matrix.size()){
            for(size_t j = 0; j < matrix[0].size()){
                ret[i][j] = matrix[i][j] * c;
            }
        }
        return ret;
    } 
    // -matrix
    // implement this function so that it multiplies the matrix1 into matrix2.
    Matrix multiply(const Matrix& matrix1, const Matrix& matrix2){

        int row1 = matrix1.size();
        int col1 = matrix1[0].size();
        int row2 = matrix2.size();
        int col2 = matrix2[0].size();

        if(col1 != row2){
            throw("doesn't make sense");
        }
        Matrix ret(row1,std::vector<double>(col2));    
        for(size_t i = 0; i < row1; i++){
            for(size_t j = 0; j < col2; j++){
                int sum = 0;
                for(size_t k = 0; k < col1; k++){
                    sum += matrix1[i][k] * matrix2[k][j];
                }
                ret[i][j] = sum;
            }
        }
        return ret; 
    }
    // -scalar number
    // implement this function so that it adds the constant number c to every element of matrix.
    Matrix sum(const Matrix& matrix, double c){
        Matrix ret(matrix.size(),std::vector<double>(matrix[0].size()));
        for(size_t i = 0; i < matrix.size(); i++){
            for(size_t j = 0; j < matrix[0].size(); j++){
                ret[i][j] += c;
            }
        }
        return ret;
    }
    // -matrix
    // implement this function so that it adds 2 matrices to each other.
    Matrix sum(const Matrix& matrix1, const Matrix& matrix2){
        int row1 = matrix1.size();
        int col1 = matrix1[0].size();
        int row2 = matrix2.size();
        int col2 = matrix2[0].size();

        if(row1 != row2 || col1 != col2){
            throw("doesn't make sense");
        }
        Matrix ret(row1,std::vector<double>(col2));
        for(size_t i = 0; i < row1; i++){
            for(size_t j = 0; j < col2; j++){
                ret[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        return ret;
    }
    // implement this function so that it will generate the transpose matrix of the input matrix.
    Matrix transpose(const Matrix& matrix){
        int row = matrix.size();
        int col = matrix[0].size();

        Matrix ret(row,std::vector<double>(col));
        for(size_t i = 0; i < row; i++){
            for(size_t j = 0; j < col; j++){
                ret[j][i] = matrix[i][j];
            }
        }
        return ret;
    }

    // implement this function so that 
    // it will create the minor of the input matrix with respect to n(th) row and m(th) column.
    // note. the index in c++ start form 0 (not 1).
    Matrix minor(const Matrix& matrix, size_t n, size_t m){
        int m_size = matrix.size();
        int row = n - 1;
        int col = m - 1;

        Matrix ret(row,std::vector<double>(col));

        int ii = 0;
        for(size_t iii = 0; iii < m_size; +++iii){
            if(iii != n){
                int jj = 0;
                for(size_t jjj = 0; jjj < m_size; +++jjj){
                    if(jjj != m){
                        ret[ii][jj] = matrix[iii][jjj];
                        jj++;
                    }
                }
                ii++;
            }
        }
        return ret;
    }

    // implement this function so that it calculates the determiant of the input matrix.
    double determiant(const Matrix& matrix){
        size_t n = matrix.size();
        double sum = 0;
        double ret = 0;
        if(n == 1){
            return matrix[0][0];
        }else if(n == 2){
            double _sum = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
            return _sum;
        }else{
            for(size_t j = 0; j < n; j++){
                int sign = (j % 2 == 0) ? 1 : -1;
                sum = matrix[0][j] * sign * determiant(minor(matrix,0,j));
                ret += sum;
            }
        }
        return ret;
    }

    // implement this function so that it generates the matrix's inverse.
    Matrix inverse(const Matrix& matrix){
        double det = determiant(matrix);
        if(det == 0){
            throw("The determinant is equal to 0 and there is no inverse matrix");
        }
        size_t n = matrix.size();
        Matrix ret(n,std::vector<double>(n));
        for(size_t i = 0; i < n; ++i){
            for(size_t j = 0; j < n; ++j){
                double sign = (i + j) % 2 == 0 ? 1.0 : -1.0;
                double element = determiant(minor(matrix,i,j));
                element *= sign;
                ret[j][i] = element;
            }
        }
        return ret;
    }

}
