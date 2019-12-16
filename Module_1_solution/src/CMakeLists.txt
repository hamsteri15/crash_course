###################
#HEADERS
###################

SET(Headers
    ./array_2d.hpp
    ./writer.hpp
    ./equation.hpp
    ./heat_equation.hpp
    ./difference_operator.hpp
    ./boundary.hpp;
    ./boundary_dirichlet.hpp;
    ./boundaries.hpp;
)


###################
#SOURCES
###################

SET(Sources
    ./main.cpp
    ./array_2d.cpp
    ./writer.cpp
    ./equation.cpp
    ./heat_equation.cpp
    ./difference_operator.cpp
    ./boundary.cpp;
    ./boundary_dirichlet.cpp;
    ./boundaries.cpp;
)

#create an executable
ADD_EXECUTABLE(HeatEquation ${Headers} ${Sources})


#place the output binary into correct dir
SET_TARGET_PROPERTIES( HeatEquation PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${APP_BINARY_DIR})