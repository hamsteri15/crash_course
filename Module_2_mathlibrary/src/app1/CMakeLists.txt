###################
#HEADERS
###################

SET(Headers
    ./some_class.hpp
)


###################
#SOURCES
###################

SET(Sources
    ./main.cpp
    ./some_class.cpp
)

#create an executable
ADD_EXECUTABLE(app1.bin ${Headers} ${Sources})

#link with math library
TARGET_LINK_LIBRARIES(app1.bin math)

#place the output binary into correct dir
SET_TARGET_PROPERTIES( app1.bin PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${APP_BINARY_DIR})