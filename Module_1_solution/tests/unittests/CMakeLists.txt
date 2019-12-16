SET(Sources
    test.cpp;
    test_array2d.cpp;
)

SET(Headers
    ./catch/catch.hpp
)



ADD_EXECUTABLE(Test.bin ${Sources})
#TARGET_LINK_LIBRARIES(Test.bin geometry)
TARGET_INCLUDE_DIRECTORIES(Test.bin PRIVATE ${CMAKE_SOURCE_DIR}/src )
SET_TARGET_PROPERTIES( Test.bin PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${TEST_BINARY_DIR}) #output to test binary dir

ADD_TEST( NAME Test
              COMMAND ${TEST_BINARY_DIR}/Test.bin
              WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/tests
            )
