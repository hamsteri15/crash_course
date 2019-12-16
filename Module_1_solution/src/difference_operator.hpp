#ifndef DifferenceOperator_hh
#define DifferenceOperator_hh

#include "array_2d.hpp"

class DifferenceOperator{
	
public:

    DifferenceOperator() = default;
    /*Implement me*/
    
    Array2d d_dx(const Array2d& in, double dx);
    Array2d d_dxdx(const Array2d& in, double dx);
    Array2d d_dy(const Array2d& in, double dy);
    Array2d d_dydy(const Array2d& in, double dy);
    
    size_t required_barriers() const {return m_required_barriers;}


protected:
 
private:

    static const size_t m_stencil_width = 3;
    static const size_t m_required_barriers = 1;

};


#endif