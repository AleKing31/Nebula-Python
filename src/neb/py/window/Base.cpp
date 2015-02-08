//#include <neb/core/context/Base.hpp>
#include <neb/core/window/Base.hpp>

#include <neb/py/window/Base.hpp>

typedef neb::py::window::Base THIS;

void		THIS::export_class()
{
	auto c = boost::python::class_<THIS>("Base");
	c.def("createContextThree", &THIS::createContextThree);
}
THIS::Base()
{
}
THIS::Base(std::weak_ptr<neb::fnd::window::Base> window)
{
	window_ = window;
}
boost::python::object				THIS::createContextThree()
{
	auto window = window_.lock();
	assert(window);

	auto context = window->createContextThree();

	return boost::python::object();
}
std::shared_ptr<THIS::T>	THIS::get_window()
{
	auto w = window_.lock();
	return w;
}

