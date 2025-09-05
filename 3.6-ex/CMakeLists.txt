cmake_minimum_required(VERSION 4.1)
project(crash_course)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED 23)

add_executable(hello)
target_sources(hello PRIVATE 
    main.cpp
)

# Tell the compiler where to find your PPP headers
target_include_directories(hello PRIVATE "$ENV{HOME}/.local/share/include")

target_compile_options(hello PRIVATE 
    -Werror
    -Wall
    -Wextra
    -Wconversion
    -Wshadow
)
