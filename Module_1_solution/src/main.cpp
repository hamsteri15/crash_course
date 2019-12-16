#include "heat_equation.hpp"
#include "writer.hpp"


/*
struct HeatEqInputs{
    double kappa, runtime, timestep;
    size_t nx, ny;
    double Lx, Ly;
    double initial_condition; 
};
*/

int main(){

    HeatEqInputs inputs;

    inputs.kappa = 1.0;
    inputs.runtime = 100.0;
    inputs.timestep = 0.1;
    inputs.nx = 251;
    inputs.ny = 251;
    inputs.Lx = 1.0;
    inputs.Ly = 1.0;
    inputs.initial_condition = 0.0;


    HeatEquation equation(inputs);
    auto solution = equation.solve();

    //solution.print();

    ArrayWriter writer;
    writer.write_mesh_to_file("mesh.dat", inputs.Lx, inputs.Ly, inputs.nx, inputs.ny);
    writer.write_to_file("solution.dat", solution);


    return 0;

}


