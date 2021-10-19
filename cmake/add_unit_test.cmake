macro(add_unit_test name)
    add_executable(${name}_float
                   ${name}.c ${M_INC}
                  )
    add_executable(${name}_double
                   ${name}.c ${M_INC}
                  )
    add_executable(${name}_int
                   ${name}.c ${M_INC}
                  )

    # add compilier options for making single/double precision and int tests
    target_compile_options(${name}_float PRIVATE -DD_TYPE=FLOAT)
    target_compile_options(${name}_double PRIVATE -DD_TYPE=DOUBLE)
    target_compile_options(${name}_int PRIVATE -DD_TYPE=INT)

    # link to the appropriate libraries
    target_link_libraries(${name}_float Matrix)
    target_link_libraries(${name}_double Matrix)
    target_link_libraries(${name}_int Matrix)

    # directories with source to link to
    target_link_directories(${name}_float PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/../src)
    target_link_directories(${name}_double PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/../src)
    target_link_directories(${name}_int PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/../src)
    
    add_test(NAME ${name}_float
             COMMAND ${name}_float
             WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            )

    add_test(NAME ${name}_double
             COMMAND ${name}_double
             WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            )

    add_test(NAME ${name}_int
             COMMAND ${name}_int
             WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            )
endmacro(add_unit_test)
