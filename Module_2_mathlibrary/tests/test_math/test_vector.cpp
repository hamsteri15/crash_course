#include "./third_party/catch/catch.hpp"
#include "./math/math_vector.hpp"


TEST_CASE("Vector constructors") {
    
    Math::Vector v1;
    Math::Vector v2(10);

}


TEST_CASE("Vector scalar operations") {
    
    Math::Vector v1(10);
    

    v1.set(1.5);
    v1 += 1.5;
    CHECK(v1(0) == 3.0);
    CHECK(v1(5) == 3.0);



    Math::Vector v2 = v1 + 1.0;

    CHECK(v2(0) == 4.0);
    CHECK(v2(5) == 4.0);
    

}