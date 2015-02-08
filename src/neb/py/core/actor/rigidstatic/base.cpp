
#include <neb/core/core/actor/rigidstatic/base.hpp>
#include <neb/py/core/actor/rigidstatic/base.hpp>

typedef neb::py::core::actor::rigidstatic::base THIS;

void		THIS::export_class()
{
}
THIS::base()
{
}
THIS::base(std::weak_ptr<neb::fnd::core::actor::rigidstatic::base> actor):
	actor_(actor)
{
	rigidactor_ = actor;
}


