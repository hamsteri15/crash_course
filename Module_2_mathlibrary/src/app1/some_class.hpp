#ifndef SomeClass_hh
#define SomeClass_hh

#include "./math/math_vector.hpp"



class SomeClass{

			
public:

    //default constructor
    SomeClass() = default;
    
    SomeClass(const Math::Vector& vec) : m_my_vector(vec) {}
    
    //Think about these two functions. 
    //When is the called abe to modify the status of 'SomeClass'?
    const Math::Vector& get_vector() const { return m_my_vector; }
    Math::Vector& get_vector()             { return m_my_vector; }
    
    
    
protected:
 
private:

    Math::Vector m_my_vector;
    
    

         	
};









#endif
