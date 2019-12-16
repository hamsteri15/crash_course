#ifndef Writer_hh
#define Writer_hh

#include "array_2d.hpp"
#include <string> //std::string
#include <iostream>
#include <fstream>

class ArrayWriter{
	
public:

    ArrayWriter() = default;
    

    void write_to_file(std::string o_file_path, const Array2d& array);
    void write_mesh_to_file(std::string o_file_path, double Lx, double Ly, size_t nx, size_t ny);
    

protected:
 
private:
    

          	
};


#endif