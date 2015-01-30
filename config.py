"""
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.8)

INCLUDE($ENV{HOME}/.config.cmake)

FIND_PACKAGE(CMakeHelper)

PROJECT(nebula_python)
INCLUDE(../../config.cmake)
INCLUDE(cmh_build_config)

SET(SHARED True)

INCLUDE(cmh_boost)
FIND_PACKAGE(Boost 1.55 COMPONENTS
	python
	REQUIRED)

FIND_PACKAGE(galaxy 0 COMPONENTS std log console REQUIRED)
FIND_PACKAGE(nebula 0 COMPONENTS core REQUIRED)


#SET(Nebula_SHARED TRUE)
#FIND_PACKAGE(Nebula COMPONENETS core REQUIRED)

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
INCLUDE_DIRECTORIES("/usr/include/python2.7")
include_directories("/usr/include/freetype2")
include_directories(${physx_INCLUDE_DIR})


ADD_DEFINITIONS("-D_DEBUG -DGAL_NET_USE_BOOST -DGLM_FORCE_RADIANS")

SET(libs
	${nebula_LIBRARIES}
	#${galaxy_LIBRARIES}
	${Boost_LIBRARIES}
	#galaxy_std_0
	#nebula_core_0
	python2.7
	pthread
   )

INCLUDE(cmh_library)

#ADD_SUBDIRECTORY(test)
"""

l = Library("nebula_python")

l.make()

