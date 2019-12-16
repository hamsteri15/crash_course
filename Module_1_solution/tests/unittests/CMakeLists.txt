SET(TestSources
    test.cpp;
    test_array2d.cpp;
    test_difference_operator.cpp;
    
)

SET(AppSources
    ${CMAKE_SOURCE_DIR}/src/array_2d.cpp;
    ${CMAKE_SOURCE_DIR}/src/difference_operator.cpp;
)


SET(Headers
    ./catch/catch.hpp
)



ADD_EXECUTABLE(Test.bin ${TestSources} ${AppSources})
TARGET_INCLUDE_DIRECTORIES(Test.bin PRIVATE ${CMAKE_SOURCE_DIR}/src )
SET_TARGET_PROPERTIES( Test.bin PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${TEST_BINARY_DIR}) #output to test binary dir

ADD_TEST( NAME Test
              COMMAND ${TEST_BINARY_DIR}/Test.bin
              WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/tests
            )
