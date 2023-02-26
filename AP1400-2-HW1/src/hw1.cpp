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
    
    void show(Matrix& matrix){
        std::cout << std::fixed << std::setprecision(3);

        for(const auto& row : tmp){
            for(const auto& elements : row){
                std::cout << std::setw(8) << elements << std::endl;
            }
        }
    }

}
