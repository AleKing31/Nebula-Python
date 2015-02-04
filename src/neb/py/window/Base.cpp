#include <neb/py/window/Base.hpp>

typedef neb::py::window::Base THIS;

void		THIS::export_class()
{
	auto c = boost::python::class_<THIS>("Base");
}
THIS::Base()
{
}
THIS::Base(std::weak_ptr<neb::core::window::Base>& window)
{
	window_ = window;
}

