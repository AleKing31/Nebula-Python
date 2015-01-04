
#include <boost/python.hpp>

#include <neb/py/core/pose.hpp>

bp::list	neb::py::math::pose::getPos() {
	bp::list l;
	l.append(pos_[0]);
	l.append(pos_[1]);
	l.append(pos_[2]);
	l.append(pos_[3]);
	return l;
}

void		export_pose()
{

	boost::python::class_<neb::py::math::pose>("pose")
		.def("getPos", &neb::py::math::pose::getPos);
	//		.def_readwrite("q", &neb::core::pose::rot_)
	//		;

}





