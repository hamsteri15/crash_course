#include "difference_operator.hpp"

Array2d DifferenceOperator::d_dx(const Array2d& in, double dx){

    Array2d ret(in.get_dims());

    for (size_t j = in.j_begin(); j < in.j_end(); ++j){
    for (size_t i = in.i_begin(); i < in.i_end(); ++i){ 

        ret(j,i) = (-0.5*in(j,i-1) + 0.5*in(j, i+1)) / dx;

    }}

    return ret;

}
Array2d DifferenceOperator::d_dxdx(const Array2d& in, double dx){
    Array2d ret(in.get_dims());

    for (size_t j = in.j_begin(); j < in.j_end(); ++j){
    for (size_t i = in.i_begin(); i < in.i_end(); ++i){ 

        ret(j,i) = (in(j,i-1) -2.0*in(j,i) + in(j, i+1)) / dx*dx;
        
    }}

    return ret;
}
Array2d DifferenceOperator::d_dy(const Array2d& in, double dy){

    Array2d ret(in.get_dims());
    
    for (size_t j = in.j_begin(); j < in.j_end(); ++j){
    for (size_t i = in.i_begin(); i < in.i_end(); ++i){ 

        ret(j,i) = (-0.5*in(j-1,i) + 0.5*in(j+1, i)) / dy;

    }}

    return ret;

}
Array2d DifferenceOperator::d_dydy(const Array2d& in, double dy){

    Array2d ret(in.get_dims());

    for (size_t j = in.j_begin(); j < in.j_end(); ++j){
    for (size_t i = in.i_begin(); i < in.i_end(); ++i){ 

        ret(j,i) = (in(j-1,i) -2.0*in(j,i) + in(j+1, i)) / dy*dy;
        
    }}

    return ret;
}