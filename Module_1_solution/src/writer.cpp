#include "writer.hpp"

void ArrayWriter::write_to_file(std::string o_file_path, const Array2d& array){

    
    std::ofstream f(o_file_path);
    f << "#data\n"; //write header

    for (size_t j = array.j_begin(); j < array.j_end(); ++j){
    for (size_t i = array.i_begin(); i < array.i_end(); ++i){

        f << std::to_string(array(j,i)) << '\n';

    }}
    f.close();



}
void ArrayWriter::write_mesh_to_file(std::string o_file_path, double Lx, double Ly, size_t nx, size_t ny){

    double dx = Lx / nx;
    double dy = Ly / ny;

    //Ńote! 0.5 delta shift from boundary!
    double x0 = 0.5 * dx; 
    double y0 = 0.5 * dy; 

    std::ofstream f(o_file_path);
    f << "#X    Y \n"; //write header

    for (size_t j = 0; j < nx; ++j){
    for (size_t i = 0; i < ny; ++i){

        double x = x0 + i*dx;
        double y = y0 + j*dy;
        
        f << std::to_string(x) << '\t' << std::to_string(y) << '\n';

    }}

    f.close();

}