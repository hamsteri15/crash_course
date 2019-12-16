#ifndef Boundaries_hh
#define Boundaries_hh

#include <memory> //std::unique_ptr

#include "boundary_dirichlet.hpp"

/*
Since only dirichlet boundaries are implemented this class is a bit useless. However, in reality
this class would provide an interface between user inputs and the solver.
*/

using boundary_ptr = std::unique_ptr<Boundary>;

class Boundaries{

public:

    Boundaries() {
        m_east = std::make_unique<BoundaryDirichlet>(1.0, BoundaryLocation::e_i0);
        m_north = std::make_unique<BoundaryDirichlet>(2.0, BoundaryLocation::e_j0);
        m_west = std::make_unique<BoundaryDirichlet>(3.0, BoundaryLocation::e_i1);
        m_south = std::make_unique<BoundaryDirichlet>(4.0, BoundaryLocation::e_j1);
    }

    void apply(Array2d& in) const{
        m_east->apply(in);
        m_north->apply(in);
        m_west->apply(in);
        m_south->apply(in);
    }

protected:
 
private:
    boundary_ptr m_east;
    boundary_ptr m_north;
    boundary_ptr m_west;
    boundary_ptr m_south;



};


#endif