###################
#HEADERS
###################

SET(Headers
    ./math_vector.hpp
    ./math_matrix.hpp
)


###################
#SOURCES
###################

SET(Sources
    ./math_vector.cpp
    ./math_matrix.cpp
)


ADD_LIBRARY(math ${Sources} ${Headers})

