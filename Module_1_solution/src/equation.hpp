#ifndef Equation_hh
#define Equation_hh

#include "array_2d.hpp"
#include "difference_operator.hpp"

class Equation{
	
public:

    Equation() = default;

    
    virtual Array2d solve() = 0;
     
    
    
    

protected:
 
private:

    

};


#endif