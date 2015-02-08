
#include <boost/python.hpp>

#include <neb/core/math/pose.hpp>
#include <neb/core/core/actor/rigiddynamic/base.hpp>
#include <neb/core/core/actor/rigidstatic/base.hpp>
#include <neb/core/core/scene/base.hpp>

#include <neb/py/core/scene/base.hpp>
#include <neb/py/core/actor/rigiddynamic/base.hpp>
#include <neb/py/core/actor/rigidstatic/base.hpp>
#include <neb/py/core/pose.hpp>

typedef neb::py::core::scene::base THIS;

THIS::base()
{}
THIS::base(std::weak_ptr<neb::fnd::core::scene::base> scene):
	scene_(scene)
{}
bp::object		THIS::createActorRigidStaticCube(
		boost::python::object& pose_obj,
		boost::python::object& size_obj)
{
	//	auto pose = boost::python::extract<neb::fnd::math::pose&>(pose_obj);
	neb::fnd::math::pose pose;

	double size = bp::extract<double>(size_obj);

	auto scene(scene_.lock());
	assert(scene);

	auto actor = std::dynamic_pointer_cast<neb::fnd::core::actor::rigidstatic::base>(scene->createActorRigidStaticCube(pose, size).lock());
	
	neb::py::core::actor::rigidstatic::base py_actor(actor);

	return bp::object(py_actor);
}
bp::object		THIS::createActorRigidDynamic()
{
	auto scene(scene_.lock());
	assert(scene);
	
	auto actor = std::dynamic_pointer_cast<neb::fnd::core::actor::rigiddynamic::base>(scene->createActorRigidDynamic().lock());

	assert(actor);

	neb::py::core::actor::rigiddynamic::base py_actor(actor);
	
	return bp::object(py_actor);
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






