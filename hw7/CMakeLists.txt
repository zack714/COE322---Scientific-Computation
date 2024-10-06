cmake_minimum_required( VERSION 3.20 )
project (L10E8 VERSION 1.0 )

message( "Using sources: L10E8.cpp" )
add_executable( L10E8 )
target_sources( L10E8 PRIVATE L10E8.cpp )

target_compile_features( L10E8 PRIVATE cxx_std_20 )
install( TARGETS L10E8 DESTINATION . )

