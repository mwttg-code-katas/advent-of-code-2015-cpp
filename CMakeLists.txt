cmake_minimum_required(VERSION 3.31)
project(advent_of_code_2015_cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target)

include_directories(include)

add_library(filereader src/filereader.cpp)

file(GLOB days "src/day*/main.cpp")
foreach (day_main ${days})
    get_filename_component(day_dir ${day_main} DIRECTORY)
    get_filename_component(day_name ${day_dir} NAME)
    file(GLOB day_sources "${day_dir}/*.cpp")
    add_executable(${day_name} ${day_sources})
    target_link_libraries(${day_name} filereader)
endforeach ()

file(GLOB day_inputs "src/day*/*input.txt")
foreach(input_file ${day_inputs})
    get_filename_component(day_dir ${input_file} DIRECTORY)
    get_filename_component(day_name ${day_dir} NAME)
    add_custom_command(TARGET ${day_name} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${input_file}
            $<TARGET_FILE_DIR:${day_name}>
    )
endforeach()
