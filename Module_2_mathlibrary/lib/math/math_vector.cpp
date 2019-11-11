#include "math_vector.hpp"

namespace Math{

//Make sure you understand what happens here.
Vector::Vector(int n) 
: m_storage(n)
{
    /*nothing*/
}


void Vector::set(double value){

    double* my_data = this->get_ptr();
    for (int idx = 0; idx < this->size(); ++idx){
        my_data[idx] = value;
    }    

}

Vector Vector::operator+(double rhs) const{

    Vector ret(this->size());
    double* ret_data = ret.get_ptr();
    const double* my_data = this->get_ptr();

    for (int idx = 0; idx < ret.size(); ++idx){
        ret_data[idx] = my_data[idx] + rhs;
    }
    return ret;
}

Vector& Vector::operator+= (double rhs){

    double* my_data = this->get_ptr();
    for (int idx = 0; idx < this->size(); ++idx){
        my_data[idx] += rhs;
    }    

    return *this;
}






} //namespace
