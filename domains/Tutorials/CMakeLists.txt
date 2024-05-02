
MIRA_REQUIRE_PACKAGE(Tutorials)

###############################################################################

MIRA_ADD_DOCUMENTATION(Tutorials
	DIRS
		doc
		include
	DEPENDS
		#RobotDataTypes
)

###############################################################################

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_LIST_DIR}/include)

###############################################################################

MIRA_ADD_LIBRARY(FloatProducer
	SHARED
	PACKAGE Tutorials
	SOURCE
		src/FloatProducer.C

	LINK_LIBS
		MIRABase
		MIRAFramework
)
