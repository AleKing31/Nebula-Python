#include <boost/python.hpp>

#include <neb/py/core/actor/Base.hpp>

typedef neb::py::core::actor::Base THIS;

void	THIS::export_class()
{
	auto c = boost::python::class_<THIS>("Base");
}

