
MIRA_REQUIRE_PACKAGE(Fibonacci)

###############################################################################

MIRA_ADD_DOCUMENTATION(Fibonacci
	DIRS
		doc
		include
	DEPENDS
		#RobotDataTypes
)

###############################################################################

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_LIST_DIR}/include)

###############################################################################

MIRA_ADD_LIBRARY(FibonacciProducer
	SHARED
	PACKAGE Fibonacci
	SOURCE
		src/FibonacciProducer.C

	LINK_LIBS
		MIRABase
		MIRAFramework
)
