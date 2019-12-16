#include "heat_equation.hpp"


Array2d HeatEquation::solve(){

    size_t nj = m_inputs.ny;
    size_t ni = m_inputs.nx;
    size_t n_barriers = m_spatial_operator.required_barriers();

    double dx = m_inputs.Lx / ni;
    double dy = m_inputs.Ly / nj;


    Array2d T(nj, n_barriers, ni, n_barriers);

    T = m_inputs.initial_condition;
    


    double time = 0.0;

    while (time < m_inputs.runtime){

        m_boundaries.apply(T);

        auto ddT_dxdx = m_spatial_operator.d_dxdx(T, dx);
        auto ddT_dydy = m_spatial_operator.d_dydy(T, dy);

        T += m_inputs.timestep * m_inputs.kappa * (ddT_dxdx + ddT_dydy); 

        time+=m_inputs.timestep;

        std::cout << "Time: " << time << " "
                  << "Max Temperature: " << T.max() << " "
                  << "Min Temperature: " << T.min() << " "
                  << std::endl;
    }

    return T;
} 