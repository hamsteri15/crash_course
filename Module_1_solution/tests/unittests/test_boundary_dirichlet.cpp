#include "./catch/catch.hpp"
#include "./boundary_dirichlet.hpp"

TEST_CASE("apply()") {
    
    BoundaryDirichlet WEST(1.0, BoundaryLocation::e_i0);
    BoundaryDirichlet NORTH(2.0, BoundaryLocation::e_j0);
    BoundaryDirichlet EAST(3.0, BoundaryLocation::e_i1);
    BoundaryDirichlet SOUTH(4.0, BoundaryLocation::e_j1);

    Array2d a(10, 1, 10, 1);

    a = -10;
    WEST.apply(a);
    NORTH.apply(a);
    EAST.apply(a);
    SOUTH.apply(a);

    //bad test but will do for now...
    for (size_t j = a.j_begin(); j < a.j_end(); ++j){
    for (size_t i = a.i_begin(); i < a.i_end(); ++i){ 
        REQUIRE(a(j,i) == -10);
    }}

}
