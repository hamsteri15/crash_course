#ifndef Boundary_hh
#define Boundary_hh

#include "array_2d.hpp"

/*
Boundary base class that should be applicable to Array2d by filling up the barrier nodes correctly
and to a discrete matrix operator by modifying the coefficients accordingly.

//TODO: Add the implementation for the matrix
*/



enum BoundaryLocation{
    e_i0, e_i1, e_j0, e_j1
};

enum BoundaryType{
    e_Neumann, e_Dirichlet
};


class Boundary{
	
public:

    Boundary() = default;
    
    Boundary(double value, BoundaryLocation loc, BoundaryType type) :
    m_value(value),
    m_location(loc),
    m_type(type)
    {}
    
    BoundaryLocation location() const {return m_location;}
    double           value() const    {return m_value; }

    

    virtual void apply(Array2d& in) const = 0;
    

protected:
 
private:
    double m_value;
    BoundaryLocation m_location;
    BoundaryType     m_type;
};


#endif