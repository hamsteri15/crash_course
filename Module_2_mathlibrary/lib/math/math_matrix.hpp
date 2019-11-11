#ifndef Matrix_hh
#define Matrix_hh

#include <vector> //Note this is a std::vector and not the 'math_vector.hpp'

namespace Math{

class Matrix{

			
public:
    //default constructor
    Matrix() = default;
    
    //construct from num cols, num rows
    Matrix(int nj, int ni);
    
    //define indexing operators
    
    //define operators 
    /*
    + 
    -
    * 
    =
    /
    +=
    -=
    *=
    /=
    */
    
    
protected:
 
private:

   
    std::vector<double>     m_storage;
    

         	
};


//make sure the scalar operations work from both sides i.e. Matrix * scalar = scalar * Matrix







} //namespace

#endif
