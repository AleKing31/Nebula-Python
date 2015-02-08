#ifndef NEB_PY_CORE_POSE_HPP
#define NEB_PY_CORE_POSE_HPP

#include <boost/python.hpp>

#include <neb/core/math/pose.hpp>

namespace bp = boost::python;

void	export_pose();

namespace neb { namespace py { namespace math {

	class pose: public neb::fnd::math::pose {
		public:
			bp::list	getPos();
	};

}}}

/*BOOST_PYTHON_MODULE(libneb-py) {

  class_<neb::fnd::pose>("pose")
  .def("p", &neb::fnd::pose::pos_)
  .def("q", &neb::fnd::pose::rot_)
  ;

  }*/

#endif

