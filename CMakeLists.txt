CMAKE_MINIMUM_REQUIRED(VERSION 2.8.8)

INCLUDE($ENV{HOME}/.config.cmake)

PROJECT(neb_py)

FIND_PACKAGE(CMakeHelper)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_STATIC_RUNTIME OFF)
add_definitions( -DBOOST_ALL_DYN_LINK )

FIND_PACKAGE(Boost 1.55 COMPONENTS
	system
	thread
	python
	serialization
	program_options
	REQUIRED)



INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
INCLUDE_DIRECTORIES("/usr/include/python2.7")
include_directories("/usr/include/freetype2")
INCLUDE_DIRECTORIES("../include")
INCLUDE_DIRECTORIES("../Debug/include")
include_directories("../Galaxy-Standard/include")
include_directories("../Galaxy-Network/include")
include_directories("../Galaxy-Log/include")
include_directories("../glm")
include_directories("../maze/include")
include_directories(${physx_INCLUDE_DIR})

link_directories("../Galaxy-Network/Debug")
link_directories("../Galaxy-Standard/Debug")
link_directories("../Galaxy-Log/Debug")
link_directories("../Debug")
link_directories("../maze/Debug")
link_directories("../Nebula-Core/Debug")


ADD_DEFINITIONS("-D_DEBUG -DGAL_NET_USE_BOOST -DGLM_FORCE_RADIANS")


SET(libs
		neb_core
		gal_std_shared
		${Boost_LIBRARIES}
		python2.7
		pthread
   )

MESSAGE(STATUS ${libs})


cmh_shared_library()

TARGET_LINK_LIBRARIES(neb_py ${libs})

#ADD_SUBDIRECTORY(test)

