#ifndef HeatEquation_hh
#define HeatEquation_hh

#include "equation.hpp"

class HeatEquation : public Equation{
	
public:

    HeatEquation() = default;

    //you need to add another constructor

    Array2d solve(); 
    
    
    

protected:
 
private:

    double m_kappa;
    double m_runtime;
    int m_nx, m_ny;
    double m_Lx, m_Ly;

    //add more if you need


};


#endif