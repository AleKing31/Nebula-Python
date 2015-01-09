
#include <neb/core/core/actor/rigiddynamic/base.hpp>
#include <neb/py/core/actor/rigiddynamic/base.hpp>

typedef neb::py::core::actor::rigiddynamic::base THIS;

void		THIS::export_class()
{
	auto c = bp::class_<THIS>("rigiddynamic");
	c.def("createShapeCuboid", &neb::py::core::actor::rigidactor::base::createShapeCuboid);
}
THIS::base()
{
}
THIS::base(std::weak_ptr<neb::core::core::actor::rigiddynamic::base> actor):
	actor_(actor)
{
	rigidactor_ = actor;
}


