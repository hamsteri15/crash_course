#ifndef Writer_hh
#define Writer_hh

#include "array_2d.hpp"
#include <string> //std::string

class ArrayWriter{
	
public:

    ArrayWriter() = default;
    

    void write_to_file(std::string o_file_path, const Array2d& array);
    void write_mesh_to_file(std::string o_file_path, double Lx, double Ly, int nx, int ny);
    

protected:
 
private:
          	
};


#endif