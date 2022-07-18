cmake_minimum_required(VERSION 3.22)
project(fifo_chain C)

set(CMAKE_C_STANDARD 99)

add_executable(fifo_chain main.c fifo_chain.c fifo_chain.h producer.c producer.h cosumer.c cosumer.h)
