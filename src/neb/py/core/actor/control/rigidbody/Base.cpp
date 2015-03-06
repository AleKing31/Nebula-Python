#include <boost/python.hpp>

#include <neb/fnd/core/actor/control/rigidbody/Base.hpp>

#include <neb/py/core/actor/control/rigidbody/Base.hpp>

typedef neb::py::core::actor::control::rigidbody::Base THIS;

THIS::Base()
{
}
THIS::Base(S s):
	O(s)
{
}
void			THIS::connect(neb::py::input::source src)
{
	auto o = get_object();
	o->connect(src.get_object());
}
void			THIS::connect(neb::py::input::js src)
{
	auto o = get_object();
	o->connect(src.get_object());
}
void					THIS::export_class()
{
	auto c = boost::python::class_<THIS>("Base");

	void	(THIS::*c1)(neb::py::input::source) = &THIS::connect;
	void	(THIS::*c2)(neb::py::input::js)     = &THIS::connect;

	c.def("connect", c1);
	c.def("connect", c2);
}

