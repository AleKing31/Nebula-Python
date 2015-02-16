#include <neb/core/context/Base.hpp>

#include <neb/py/context/Base.hpp>

typedef neb::py::context::Base THIS;

THIS::Base()
{
}
THIS::Base(std::weak_ptr<neb::fnd::context::Base> c):
	context_(c)
{
}
boost::python::object	THIS::get_environ()
{
}
void		THIS::export_class()
{
	auto c = boost::python::class_<THIS>("Base");
	c.def("get_environ", &THIS::get_environ);
}

