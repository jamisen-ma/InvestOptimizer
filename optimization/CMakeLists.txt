cmake_minimum_required(VERSION 3.10)
project(PortfolioOptimization)

set(CMAKE_CXX_STANDARD 14)

find_package(Eigen3 3.3 REQUIRED)

add_executable(PortfolioOptimization main.cpp)
target_link_libraries(PortfolioOptimization Eigen3::Eigen)
