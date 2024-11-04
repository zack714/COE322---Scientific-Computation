cmake_minimum_required( VERSION 3.20 )
project( hw11 VERSION 1.0 )

message( "Using sources: newtonComp.cpp" )
add_executable( hw11 )
target_sources( hw11 PRIVATE newtonComp.cpp )

target_compile_features( hw11 PRIVATE cxx_std_17 )
install( TARGETS hw11 DESTINATION . )

