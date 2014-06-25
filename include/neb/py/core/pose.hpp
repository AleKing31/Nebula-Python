#ifndef NEB_PY_CORE_POSE_HPP
#define NEB_PY_CORE_POSE_HPP

#include <boost/python.hpp>

void	export_pose();

/*BOOST_PYTHON_MODULE(libneb-py) {

	class_<neb::core::pose>("pose")
		.def("p", &neb::core::pose::pos_)
		.def("q", &neb::core::pose::rot_)
		;

}*/

#endif

