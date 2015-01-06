
#include <boost/python.hpp>

#include <neb/core/math/pose.hpp>
#include <neb/core/core/scene/base.hpp>

#include <neb/py/core/scene/base.hpp>
#include <neb/py/core/actor/rigiddynamic/base.hpp>
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
neb::py::core::actor::rigiddynamic::base	THIS::createActorRigidDynamic()
{
	auto scene(scene_.lock());
	assert(scene);
	
	auto actor = scene->createActorRigidDynamic();
	
	neb::py::core::actor::rigiddynamic::base py_actor(actor);

	return py_actor;
}

void		export_scene()
{
	auto c = bp::class_<neb::py::core::scene::base>("scene");
	c.def("createActorRigidStaticCube", &neb::py::core::scene::base::createActorRigidStaticCube);
	c.def("createActorRigidDynamic", &neb::py::core::scene::base::createActorRigidDynamic);

	//        .def("greet", &World::greet)
	//       .def("set", &World::set)
	//    ;
}






