# first we add the executable that generate the table
add_executable (MakeTable MakeTable.cpp)

# add the command to generate the source code
add_custom_command (
	OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
	COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
	DEPENDS MakeTable
)

# add the binary tree directory to the search path for
# include files
include_directories ( ${CMAKE_CURRENT_BINARY_DIR} )

# add the main library
add_library (MathFunctions mysqrt.cpp ${CMAKE_CURRENT_BINARY_DIR}/Table.h)

install (TARGETS MathFunctions DESTINATION bin)
install (FILES MathFunctions.h DESTINATION include)
