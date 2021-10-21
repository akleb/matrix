macro(add_unit_test name)
    foreach(TYPE int float double)
        add_executable(${name}_${TYPE}
                        ${name}.cpp ${M_INC}
                        )
        
        # add compilier options for making single/double precision and int tests
        target_compile_options(${name}_${TYPE} PRIVATE -DD_TYPE=${TYPE}
                                               PRIVATE -g3
                                               PRIVATE -O0)
        # link to the appropriate libraries
        target_link_libraries(${name}_${TYPE} Matrix)
        
        add_test(NAME ${name}_${TYPE}
                COMMAND ${name}_${TYPE}
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                )
    endforeach()
endmacro(add_unit_test)
