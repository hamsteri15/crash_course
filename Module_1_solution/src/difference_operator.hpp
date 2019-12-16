#ifndef DifferenceOperator_hh
#define DifferenceOperator_hh

#include "array_2d.hpp"

class DifferenceOperator{
	
public:

    /*Implement me*/
    
    Array2d d_dx(const Array2d& in, double dx);
    Array2d d_dxdx(const Array2d& in, double dx);
    Array2d d_dy(const Array2d& in, double dx);
    Array2d d_dydy(const Array2d& in, double dx);
    

protected:
 
private:
          	
};


#endif