
#include <boost/version.hpp>

#include <neb/py/app/base.hpp>
#include <neb/py/core/pose.hpp>
#include <neb/py/core/scene/base.hpp>
#include <neb/py/core/shape/cuboid/Desc.hpp>
#include <neb/py/util/config.hpp>

/*
#if BOOST_VERSION==105500
#	warning 1_55
#elif BOOST_VERSION==104900
#	warning 1_49
#else
#	error
#endif
*/

class dummy_shape {};
class dummy_shape_cuboid {};

BOOST_PYTHON_MODULE(PY_LIB_NAME)
{
	export_pose();
	export_scene();
	export_app();
	
	bp::scope scope_shape = bp::class_<dummy_shape>("shape");
	bp::scope scope_shape_cuboid = bp::class_<dummy_shape_cuboid>("cuboid");
	
	neb::py::core::shape::cuboid::Desc::export_class();
}

