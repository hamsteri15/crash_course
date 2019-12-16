#include "boundary_dirichlet.hpp"

void BoundaryDirichlet::apply(Array2d& in) const{

    switch(location()){
        case BoundaryLocation::e_i0:
            apply_i0(in); break;       
        case BoundaryLocation::e_j0:
            apply_j0(in); break;
        case BoundaryLocation::e_i1:
            apply_i1(in); break;     
       default:
            apply_j1(in); break;                 
    }



}


void BoundaryDirichlet::apply_i0(Array2d& in) const{

    for (size_t j = in.j_begin(); j < in.j_end(); ++j){
    for (size_t i = in.I_BEGIN(); i < in.i_begin(); ++i){
        in(j,i) = value();
    }}


}

void BoundaryDirichlet::apply_j0(Array2d& in) const{

    for (size_t j = in.J_BEGIN(); j < in.j_begin(); ++j){
    for (size_t i = in.i_begin(); i < in.i_end(); ++i){
        in(j,i) = value();
    }}


}

void BoundaryDirichlet::apply_i1(Array2d& in) const{

    for (size_t j = in.j_begin(); j < in.j_end(); ++j){
    for (size_t i = in.i_end(); i < in.I_END(); ++i){
        in(j,i) = value();
    }}


}

void BoundaryDirichlet::apply_j1(Array2d& in) const{

    for (size_t j = in.j_end(); j < in.J_END(); ++j){
    for (size_t i = in.i_begin(); i < in.i_end(); ++i){
        in(j,i) = value();
    }}


}