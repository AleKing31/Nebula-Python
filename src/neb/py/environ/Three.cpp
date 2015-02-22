#include <neb/fnd/environ/Three.hpp>

#include <neb/py/environ/Three.hpp>

typedef neb::py::environ::Three THIS;

THIS::Three()
{
}
THIS::Three(std::weak_ptr<neb::fnd::environ::Three> e):
	neb::py::environ::Base(e)
{
}
void		THIS::export_class()
{
	auto c = boost::python::class_<THIS, boost::python::bases<neb::py::environ::Base>>("Three");
}


