cmake_minimum_required( VERSION 3.20 )
project( fizzBuzz VERSION 1.0 )

message( "Using sources: fizzBuzz.cpp" )
add_executable( fizzBuzz.cpp )
target_sources( fizzBuzz PRIVATE fizzBuzz.cpp )

target_compile_features( fizzBuzz PRIVATE cxx_std_17 )
install( TARGETS fizzBuzz DESTINATION . )
install( FILES run.sh DESTINATION . )
