
#include <neb/core/core/actor/rigiddynamic/base.hpp>
#include <neb/py/core/actor/rigiddynamic/base.hpp>

typedef neb::py::core::actor::rigiddynamic::base THIS;

void		THIS::export_class()
{
	auto c = bp::class_<THIS>("rigiddynamic");
}
THIS::base()
{
}
THIS::base(std::weak_ptr<neb::core::core::actor::rigiddynamic::base> actor):
	actor_(actor)
{
	rigidactor_ = actor;
}


