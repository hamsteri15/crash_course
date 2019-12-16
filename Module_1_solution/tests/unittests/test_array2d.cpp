#include "./catch/catch.hpp"
#include "./array_2d.hpp"


TEST_CASE("Array2d constructors") {
    

    Array2d a1(10, 0, 10, 0);
    a1(3,3) = 32.013;

    Array2d a2(a1);
    CHECK(a2(3,3) == 32.013);
    
    Array2d a3;
    a3 = a2;
    CHECK(a3(3,3) == 32.013);
    CHECK(a3.get_dims() == a2.get_dims());

    

}
TEST_CASE("Array2d indexing operations") {
    
    Array2d a1(32, 1, 33, 3);

    REQUIRE_THROWS(a1(a1.J_END(), 0 ));
    REQUIRE_THROWS(a1(0, a1.I_END() ));

}

TEST_CASE("Array2d math operations") {
    
    Array2d a1(32, 1, 33, 3);


    a1 = 431.0;
    CHECK(a1 == 431.0);


    a1 = 1.0;
    Array2d a2(a1);
    Array2d a3(a1);

    CHECK(a2 == a1);
    CHECK(a3 == a1);

    a1 = 10;
    a2 = 0.0;
    a3 = -1.0;

    Array2d a4 = 3*a1 + a2 - a3/10;
    
    CHECK(a4 == 3*10 + 0.0 - -1.0/10);
    

}
