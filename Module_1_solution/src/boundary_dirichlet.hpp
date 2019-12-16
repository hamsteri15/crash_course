#ifndef BoundaryDirichlet_hh
#define BoundaryDirichlet_hh

#include "boundary.hpp"

/*
A naive dirichlet boundary class that just fills up the barrier with a user input value
*/

class BoundaryDirichlet : public Boundary{
	
public:

    BoundaryDirichlet() = default;
    
    BoundaryDirichlet(double value, BoundaryLocation loc) :
    Boundary(value, loc, BoundaryType::e_Dirichlet)
    {}
    
    virtual void apply(Array2d& in) const;
    

    

protected:
 
private:

    void apply_i0(Array2d& in) const;
    void apply_j0(Array2d& in) const;
    void apply_i1(Array2d& in) const;
    void apply_j1(Array2d& in) const;
    
};


#endif