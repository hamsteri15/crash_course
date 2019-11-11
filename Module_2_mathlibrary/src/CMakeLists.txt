SET(SubDirs 
    app1 
    )
SUBDIRS(${SubDirs} )

#all applications include everything inside lib
#this means that all header includes from the math library must be relative to this path
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/lib)
