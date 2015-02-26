
#include <boost/python.hpp>

#include <neb/fnd/math/pose.hpp>
#include <neb/fnd/core/actor/rigiddynamic/Base.hpp>
#include <neb/fnd/core/actor/rigidbody/desc.hpp>
#include <neb/fnd/core/actor/rigidstatic/base.hpp>
#include <neb/fnd/core/scene/Base.hpp>
#include <neb/py/core/scene/base.hpp>
#include <neb/py/core/actor/rigiddynamic/base.hpp>
#include <neb/py/core/actor/rigidstatic/base.hpp>
#include <neb/py/core/pose.hpp>

typedef neb::py::core::scene::base THIS;

THIS::base()
{
}
THIS::base(std::weak_ptr<THIS::FND_TYPE> scene):
	_M_scene(scene)
{
}
boost::python::object		THIS::createActorRigidStaticCube(
		boost::python::object& pose_obj,
		boost::python::object& size_obj)
{
	//	auto pose = boost::python::extract<neb::fnd::math::pose&>(pose_obj);
	neb::fnd::math::pose pose;

	double size = bp::extract<double>(size_obj);

	auto scene = get_scene();

	auto actor = std::dynamic_pointer_cast<neb::fnd::core::actor::rigidstatic::base>(scene->createActorRigidStaticCube(pose, size).lock());
	
	neb::py::core::actor::rigidstatic::base py_actor(actor);

	return bp::object(py_actor);
}
bp::object		THIS::createActorRigidDynamic()
{
	auto scene = get_scene();
	
	auto actor = std::dynamic_pointer_cast<neb::fnd::core::actor::rigiddynamic::base>(scene->createActorRigidDynamic().lock());

	assert(actor);

	neb::py::core::actor::rigiddynamic::base py_actor(actor);
	
	return bp::object(py_actor);
}
bp::object		THIS::createLightPoint()
{
	auto scene = get_scene();

	scene->createActorLightPoint(glm::vec3()).lock();
	
	return bp::object();
}
bp::object		THIS::createActorRigidDynamicCuboid()
{
	auto scene = get_scene();
	assert(scene);

	neb::fnd::core::actor::rigidbody::desc ad;
	//ad.pose.pos_.z = -20;

	neb::fnd::core::shape::cuboid::Desc sd;
	
	auto actor_fnd = scene->createActorRigidDynamicCuboid(ad, sd).lock();

	auto actor = std::dynamic_pointer_cast<neb::fnd::core::actor::rigiddynamic::base>(actor_fnd);

	assert(actor);
	
	neb::py::core::actor::rigiddynamic::base py_actor(actor);

	return bp::object(py_actor);
}
std::shared_ptr<THIS::FND_TYPE>	THIS::get_scene()
{
	auto s = _M_scene.lock();
	assert(s);
	return s;
}
void				THIS::export_class()
{
	auto c = bp::class_<neb::py::core::scene::base>("scene");
	c.def("createActorRigidStaticCube", &neb::py::core::scene::base::createActorRigidStaticCube);
	c.def("createActorRigidDynamic", &neb::py::core::scene::base::createActorRigidDynamic);
	c.def("createActorRigidDynamicCuboid", &neb::py::core::scene::base::createActorRigidDynamicCuboid);
	c.def("createLightPoint", &neb::py::core::scene::base::createLightPoint);

	//        .def("greet", &World::greet)
	//       .def("set", &World::set)
	//    ;
}






