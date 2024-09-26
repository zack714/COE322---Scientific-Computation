cmake_minimum_required( VERSION 3.20 )
project( objectNewton VERSION 1.0 )

message( "Using sources: objectNewton.cpp" )
add_executable( objectNewton )
target_sources( objectNewton PRIVATE objectNewton.cpp )

target_compile_features( objectNewton PRIVATE cxx_std_17 )
install( TARGETS objectNewton DESTINATION . )

