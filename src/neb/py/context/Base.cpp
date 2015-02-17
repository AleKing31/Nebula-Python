#include <neb/core/context/Base.hpp>

#include <neb/py/context/Base.hpp>
#include <neb/py/environ/Base.hpp>

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
	auto c(context_.lock());
	assert(c);
	
	auto e = c->get_environ();

	neb::py::environ::Base e_py(e);

	return boost::python::object(e_py);
}
void		THIS::export_class()
{
	auto c = boost::python::class_<THIS>("Base");
	c.def("get_environ", &THIS::get_environ);
}

