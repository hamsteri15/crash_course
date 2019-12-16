#ifndef HeatEquation_hh
#define HeatEquation_hh

#include <iostream>

#include "equation.hpp"
#include "boundaries.hpp"
#include "difference_operator.hpp"

struct HeatEqInputs{
    double kappa, runtime, timestep;
    size_t nx, ny;
    double Lx, Ly;
    double initial_condition; 
};

class HeatEquation : public Equation{
	
public:

    HeatEquation() = default;

    HeatEquation(const HeatEqInputs& inputs) :
    m_boundaries(Boundaries()),
    m_inputs(inputs),
    m_spatial_operator(DifferenceOperator())
    {}

    Array2d solve(); 
    
    
    

protected:
 
private:

    Boundaries              m_boundaries;
    HeatEqInputs            m_inputs;
    DifferenceOperator      m_spatial_operator;

};


#endif