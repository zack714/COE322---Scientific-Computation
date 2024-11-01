cmake_minimum_required( VERSION 3.20 )
project( hw10 VERSION 1.0 )
#project( require VERSION 1.0 )

set(EXTRA_SOURCES zeroclasstest.cpp zeroclasslib.hpp)
message( "Using sources: zeroclassimp.cpp ${EXTRA_SOURCES}" )
add_executable( hw10 )
target_sources( hw10 PRIVATE zeroclassimp.cpp zeroclasstest.cpp zeroclasslib.hpp )
 
##
## Extra packages: catch2
##
find_package( PkgConfig REQUIRED )
pkg_check_modules( CATCH2 REQUIRED catch2-with-main )
target_include_directories(
	${PROJECT_NAME} PUBLIC
	${CATCH2_INCLUDE_DIRS}
	)
target_link_directories(
	${PROJECT_NAME} PUBLIC
	${CATCH2_LIBRARY_DIRS}
	)
target_link_libraries(
	${PROJECT_NAME} PUBLIC
	${CATCH2_LIBRARIES}
	)

set_target_properties(
	${PROJECT_NAME} PROPERTIES
	BUILD_RPATH   "${CATCH2_LIBRARY_DIRS}"
	INSTALL_RPATH "${CATCH2_LIBRARY_DIRS}"
    )

install( TARGETS hw10 DESTINATION . )

