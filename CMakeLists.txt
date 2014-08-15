CMAKE_MINIMUM_REQUIRED(VERSION 2.8.8)

INCLUDE($ENV{HOME}/.config.cmake)

PROJECT(nebula_python)

FIND_PACKAGE(CMakeHelper)


cmh_boost_shared()
FIND_PACKAGE(Boost 1.55 COMPONENTS
	system
	thread
	python
	serialization
	REQUIRED)

FIND_PACKAGE(galaxy_std_shared REQUIRED)
FIND_PACKAGE(nebula_core_shared REQUIRED)


#SET(Nebula_SHARED TRUE)
#FIND_PACKAGE(Nebula COMPONENETS core REQUIRED)

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
INCLUDE_DIRECTORIES("/usr/include/python2.7")
include_directories("/usr/include/freetype2")
include_directories(${physx_INCLUDE_DIR})


ADD_DEFINITIONS("-D_DEBUG -DGAL_NET_USE_BOOST -DGLM_FORCE_RADIANS")

SET(libs
	${Nebula_LIBRARIES}
	${Galaxy_LIBRARIES}
	${Boost_LIBRARIES}
	python2.7
	pthread
   )

cmh_shared_library()

MESSAGE(STATUS "add ${PROJECT_BINARY_DIR} to PYTHONPATH")
SET(ENV{PYTHONPATH} $ENV{PYTHONPATH} ${PROJECT_BINARY_DIR})

#ADD_SUBDIRECTORY(test)

