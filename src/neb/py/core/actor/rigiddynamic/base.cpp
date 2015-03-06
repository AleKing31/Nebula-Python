#include <cassert>

#include <neb/fnd/core/actor/rigiddynamic/Base.hpp>
#include <neb/fnd/window/Base.hpp>

#include <neb/py/core/actor/control/rigidbody/Base.hpp>
#include <neb/py/core/actor/rigiddynamic/base.hpp>
#include <neb/py/window/Base.hpp>

typedef neb::py::core::actor::rigidactor::base BASE;
typedef neb::py::core::actor::rigiddynamic::base THIS;

THIS::base()
{
	assert(0);
}
THIS::base(std::weak_ptr<neb::fnd::core::actor::rigiddynamic::base> actor):
	neb::py::core::actor::Base(actor),
	neb::py::core::actor::rigidactor::base(actor)
{
	assert(actor.lock());
}
neb::py::core::actor::control::rigidbody::Base		THIS::createControlManual(
		boost::python::object& src_obj)
{
	auto rigidactor = get_rigidactor();
	auto rigidbody = std::dynamic_pointer_cast<neb::fnd::core::actor::rigidbody::base>(rigidactor);
	assert(rigidbody);

	// src
	auto src_ex = boost::python::extract<neb::py::window::Base&>(src_obj);
	assert(src_ex.check());
	auto src_py = src_ex();

	auto src = src_py.window_.lock();
	assert(src);

	auto control = rigidbody->createControlManual(src).lock();

	return neb::py::core::actor::control::rigidbody::Base(control);
}
void			THIS::export_class()
{
	typedef neb::py::core::actor::rigidactor::base BASE;

	auto c = boost::python::class_<THIS, boost::python::bases<BASE>>("rigiddynamic");
	
	c.def("createShapeCuboid", &neb::py::core::actor::rigidactor::base::createShapeCuboid);
	c.def("createWeaponSimpleProjectile", &neb::py::core::actor::rigidactor::base::createWeaponSimpleProjectile);
	c.def("createControlManual", &neb::py::core::actor::rigiddynamic::base::createControlManual);
}


