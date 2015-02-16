#include <neb/core/environ/Base.hpp>

#include <neb/py/environ/Base.hpp>

typedef neb::py::environ::Base THIS;

THIS::Base()
{
}
THIS::Base(std::weak_ptr<neb::fnd::environ::Base> c):
	environ_(c)
{
}
void		THIS::export_class()
{
	auto c = boost::python::class_<THIS>("Base");
}

