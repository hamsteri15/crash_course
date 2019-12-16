#ifndef Array2d_hh
#define Array2d_hh

#include <iostream>
#include <vector> //std::vector
#include <cstddef> //size_t
#include <stdexcept> //std::runtime_error

struct Dimensions2d{
    size_t nj, nbj, ni, nbi;

    size_t size() const { return (nj + 2*nbj) * (ni + 2*nbi); }

    std::vector<size_t> to_vector() const {return {nj, nbj, ni, nbi};}

    bool operator==(const Dimensions2d& dims) const {
        return to_vector() == dims.to_vector();
    }

};

class Array2d{
	
public:

    Array2d() = default;

    //construct from number of nodes and the number of barriers in the respective direction
    Array2d(size_t nj, size_t nbj, size_t ni, size_t nbi) : 
    m_dims({nj, nbj, ni, nbi}), 
    m_data(m_dims.size(), 0.0)
    {}
    
    Array2d(const Dimensions2d& dims) :
    m_dims(dims),
    m_data(dims.size(), 0.0)
    {}


    const Dimensions2d& get_dims() const {return m_dims;}

    //get the interior and neglect barriers
    Array2d get_interior() const{

        Array2d ret(m_dims.nj, 0, m_dims.ni, 0);

        for (size_t j = 0; j < m_dims.nj; ++j){
        for (size_t i = 0; i < m_dims.ni; ++i){
            ret(j,i) = this->operator()(j - m_dims.nbj, i - m_dims.nbi);
        }}
        return ret;
    }

    //total storage size
    size_t size() const {return m_data.size();}

    //get the storgae
    const std::vector<double> get_data() const {return m_data;}

    

    //get loop bounds of the interior, i.e. neglect barriers
    size_t i_begin() const {return m_dims.nbi;}
    size_t i_end() const {return m_dims.ni + m_dims.nbi;}

    size_t j_begin() const {return m_dims.nbj;}
    size_t j_end() const {return m_dims.nj + m_dims.nbj;}

    //dimensions with barriers
    size_t I_BEGIN() const {return 0;}
    size_t I_END() const {return m_dims.ni + 2*m_dims.nbi;}

    size_t J_BEGIN() const {return 0;}
    size_t J_END() const {return m_dims.nj + 2*m_dims.nbj;}

    //indexing operators
    const double& operator()(size_t j, size_t i) const{
        bounds_check(j,i);
        size_t NX = m_dims.ni + 2*m_dims.nbi;
        return m_data[i + NX * j];
    }

    double& operator()(size_t j, size_t i){
        bounds_check(j,i);
        size_t NX = m_dims.ni + 2*m_dims.nbi;
        return m_data[i + NX * j];
    }

    const double& operator()(size_t idx) const{ return m_data[idx]; }
    double& operator()(size_t idx){ return m_data[idx]; }
        
    
    //in debug mode, apply bounds checking
    #ifdef DEBUG
    void bounds_check(size_t j, size_t i) const {
        if (j >= m_dims.nj + 2*m_dims.nbj){
            throw std::runtime_error("Array j index out of bounds");
        }
        if (i >= m_dims.ni + 2*m_dims.nbi){
            throw std::runtime_error("Array i index out of bounds");
        }

    }
    #else
    void bounds_check(size_t j, size_t i) const {}
    #endif // DEBUG
    

    //Operator overloads. NOTE! These are barrier inclusive!
    Array2d& operator = (double rhs) { for (size_t i = 0; i < size(); ++i) m_data[i] = rhs; return *this; }
    

    Array2d& operator +(void){ return *this; }
    Array2d& operator -(void){ for (size_t i = 0; i < size(); ++i) m_data[i] = -m_data[i]; return *this; }
    //scalar  
    Array2d& operator += (double rhs){ for (size_t i = 0; i < size(); ++i) m_data[i] += rhs; return *this; }
    Array2d& operator -= (double rhs){ for (size_t i = 0; i < size(); ++i) m_data[i] -= rhs; return *this; }
    Array2d& operator *= (double rhs){ for (size_t i = 0; i < size(); ++i) m_data[i] *= rhs; return *this; }
    Array2d& operator /= (double rhs){ for (size_t i = 0; i < size(); ++i) m_data[i] /= rhs; return *this; }
    //
    Array2d operator+ (double rhs) const { Array2d ret(*this); ret += rhs; return ret; }
    Array2d operator- (double rhs) const { Array2d ret(*this); ret -= rhs; return ret; }
    Array2d operator* (double rhs) const { Array2d ret(*this); ret *= rhs; return ret; }
    Array2d operator/ (double rhs) const { Array2d ret(*this); ret /= rhs; return ret; }
    
    

    //Array2d
    Array2d& operator += (const Array2d& rhs){ 
        auto rhs_data = rhs.get_data(); 
        for (size_t i = 0; i < size(); ++i) { m_data[i] += rhs_data[i]; } 
        return *this; 
    }
    
    Array2d& operator -= (const Array2d& rhs){ 
        auto rhs_data = rhs.get_data(); 
        for (size_t i = 0; i < size(); ++i) { m_data[i] -= rhs_data[i]; } 
        return *this; 
    }

    Array2d& operator *= (const Array2d& rhs){ 
        auto rhs_data = rhs.get_data(); 
        for (size_t i = 0; i < size(); ++i) { m_data[i] *= rhs_data[i]; } 
        return *this; 
    }

    Array2d& operator /= (const Array2d& rhs){ 
        auto rhs_data = rhs.get_data(); 
        for (size_t i = 0; i < size(); ++i) { m_data[i] /= rhs_data[i]; } 
        return *this; 
    }

    Array2d operator+ (const Array2d& rhs) const { Array2d ret(*this); ret += rhs; return ret; }
    Array2d operator- (const Array2d& rhs) const { Array2d ret(*this); ret -= rhs; return ret; }
    Array2d operator* (const Array2d& rhs) const { Array2d ret(*this); ret *= rhs; return ret; }
    Array2d operator/ (const Array2d& rhs) const { Array2d ret(*this); ret /= rhs; return ret; }
    

    bool operator == (double rhs) const{ 

        for (size_t i = 0; i < size(); ++i){
            if (m_data[i] != rhs) {return false;}
        } 
        return true;
    }


    bool operator == (const Array2d& rhs) const{ 

        if (! (get_dims() == rhs.get_dims()) ){
            return false;
        }

        for (size_t i = 0; i < size(); ++i){
            if (m_data[i] != rhs(i)) return false;
        } 
        return true;
    }
    
    void print() const{
        for (size_t j = J_BEGIN(); j < J_END(); ++j){
        for (size_t i = I_BEGIN(); i < I_END(); ++i){
            std::cout << this->operator()(j,i) << " ";
        }
        std::cout << std::endl;
        }
        std::cout << "=======" << std::endl;    
    }


protected:
 
private:
    Dimensions2d        m_dims;
    std::vector<double> m_data;     	
};


//ensure that scalar operations work on both sides
inline Array2d operator+(double lhs, const Array2d& rhs){
    return rhs + lhs;
}


inline Array2d operator-(double lhs, const Array2d& rhs){
    auto ret(rhs);
    return -ret + lhs;
}

inline Array2d operator*(double lhs, const Array2d& rhs){
    return rhs*lhs;
}

inline Array2d operator/(double lhs, const Array2d& rhs){
    auto ret(rhs);
    for (size_t i = 0; i < rhs.size(); ++i){ ret(i) = lhs / rhs(i); }
    return ret;
}





#endif