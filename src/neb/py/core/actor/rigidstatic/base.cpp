
#include <neb/core/core/actor/rigidstatic/base.hpp>

#include <neb/py/core/actor/rigidstatic/base.hpp>

typedef neb::py::core::actor::rigidactor::base BASE;
typedef neb::py::core::actor::rigidstatic::base THIS;

THIS::base()
{
}
THIS::base(std::weak_ptr<neb::fnd::core::actor::rigidstatic::base> actor):
	BASE(actor)
{
}
void		THIS::export_class()
{
	auto c = boost::python::class_<THIS>("Base");
}

