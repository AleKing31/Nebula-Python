#include <boost/python.hpp>

#include <neb/py/input/js.hpp>

typedef neb::py::input::js THIS;

THIS::js()
{
}
THIS::js(S s):
	O(s)
{
}
void		THIS::export_class()
{
	auto c = boost::python::class_<THIS>("js");
}


