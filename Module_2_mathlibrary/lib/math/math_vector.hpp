#ifndef Matrix_hh
#define Matrix_hh

#include <vector> //Note this is a std::vector and not the 'math_vector.hpp'

namespace Math{

class Vector{

			
public:
    //default constructor
    Vector() = default;
    
    //construct from num elements
    Vector(int n);
    
    //vector size (number of elements)
    int size() const { return m_storage.size(); }

    double*       get_ptr()                  { return m_storage.data(); }
    const double* get_ptr() const            { return m_storage.data(); }


    void          set(double value);


    //Indexing operators Vector(idx)
    const double& operator() (int idx) const { return m_storage[idx]; }
    double&       operator() (int idx)       { return m_storage[idx]; }
    
   
    //Think about the return values of these. 
    //Why is it that sometimes a reference is returned and sometimes a copy of *this ?

    //an example for vector += scalar
    Vector& operator += (double rhs);

    //an example for vector + scalar
    Vector operator  +  (double rhs) const; 

    //an example for vector += vectror
    Vector& operator += (const Vector& rhs);
    


     //define arithmetic operators 
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


//make sure the scalar operations work from both sides i.e. Vector * scalar = scalar * Vector







} //namespace

#endif
