cmake_minimum_required(VERSION 4.1)
project(PPP3)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED 23)

add_executable(calc)
target_sources(calc PRIVATE 
    main.cpp
)

# Tell the compiler where to find your PPP headers
target_include_directories(calc PRIVATE "$ENV{HOME}/.local/share/include")

target_compile_options(calc PRIVATE 
    -Werror
    -Wall
    -Wextra
    -Wconversion
    -Wshadow
)
