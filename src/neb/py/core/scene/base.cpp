
#include <boost/python.hpp>

#include <neb/core/math/pose.hpp>
#include <neb/core/core/scene/base.hpp>

#include <neb/py/core/scene/base.hpp>
#include <neb/py/core/pose.hpp>

typedef neb::py::core::scene::base THIS;

THIS::base()
{}
THIS::base(std::weak_ptr<neb::core::core::scene::base> scene):
	scene_(scene)
{}
void			THIS::createActorRigidStaticCube(
		boost::python::object& pose_obj,
		boost::python::object& size_obj)
{

	//	auto pose = boost::python::extract<neb::core::math::pose&>(pose_obj);
	neb::core::math::pose pose;

	double size = bp::extract<double>(size_obj);

	auto scene(scene_.lock());
	assert(scene);

	scene->createActorRigidStaticCube(pose, size);

}

void		export_scene()
{

	boost::python::class_<neb::py::core::scene::base>("scene")
		.def("createActorRigidStaticCube", &neb::py::core::scene::base::createActorRigidStaticCube);
	//        .def("greet", &World::greet)
	//       .def("set", &World::set)
	//    ;
}






