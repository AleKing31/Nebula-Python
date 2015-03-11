#include <neb/py/net/server/Base.hpp>

typedef neb::py::net::server::Base THIS;

THIS::Base()
{
}
THIS::Base(W w):
	O(w)
{
}
void		THIS::export_class()
{
	auto c = boost::python::class_<THIS>("server");
	
	
}

