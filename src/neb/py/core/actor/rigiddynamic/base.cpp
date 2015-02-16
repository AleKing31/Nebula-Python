#include <cassert>
#include <neb/core/core/actor/rigiddynamic/base.hpp>

#include <neb/py/core/actor/rigiddynamic/base.hpp>

typedef neb::py::core::actor::rigiddynamic::base THIS;

THIS::base()
{
	assert(0);
}
THIS::base(std::weak_ptr<neb::fnd::core::actor::rigiddynamic::base> actor):
	neb::py::core::actor::rigidactor::base(actor),
	actor_(actor)
{
	assert(actor.lock());
}
void		THIS::export_class()
{
	auto c = bp::class_<THIS>("rigiddynamic");
	c.def("createShapeCuboid", &neb::py::core::actor::rigidactor::base::createShapeCuboid);
	c.def("createWeaponSimpleProjectile", &neb::py::core::actor::rigidactor::base::createWeaponSimpleProjectile);
}


