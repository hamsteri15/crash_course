#include "./catch/catch.hpp"
#include "./difference_operator.hpp"

TEST_CASE("First derivatives") {
    
    Array2d a1(10, 1, 10, 1);
    Array2d a2(10, 1, 10, 1);
    
    //set linear condition
    for (size_t j = a1.J_BEGIN(); j < a1.J_END(); ++j){
    for (size_t i = a1.I_BEGIN(); i < a1.I_END(); ++i){
        a1(j,i) = i;
        a2(j,i) = j;
    }}

    DifferenceOperator d;
    
    auto ddx = d.d_dx(a1, 1.0);
    auto ddy = d.d_dy(a2, 1.0);
    
   
    CHECK(ddx == ddy);

    for (size_t j = a1.j_begin(); j < a1.j_end(); ++j){
    for (size_t i = a1.i_begin(); i < a1.i_end(); ++i){ 

        REQUIRE(ddx(j,i) == 1.0);
        REQUIRE(ddy(j,i) == 1.0);
        
    }}



}

TEST_CASE("Second derivatives") {
    
    Array2d a1(10, 1, 10, 1);
    Array2d a2(10, 1, 10, 1);
    
    //set quadratic condition
    for (size_t j = a1.J_BEGIN(); j < a1.J_END(); ++j){
    for (size_t i = a1.I_BEGIN(); i < a1.I_END(); ++i){
        a1(j,i) = i*i;
        a2(j,i) = j*j;
    }}

    DifferenceOperator d;
    
    auto ddx = d.d_dxdx(a1, 1.0);
    auto ddy = d.d_dydy(a2, 1.0);
    
   
    CHECK(ddx == ddy);

    for (size_t j = a1.j_begin(); j < a1.j_end(); ++j){
    for (size_t i = a1.i_begin(); i < a1.i_end(); ++i){ 

        REQUIRE(ddx(j,i) == 2.0);
        REQUIRE(ddy(j,i) == 2.0);
        
    }}



}