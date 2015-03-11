#include <gal/stl/deleter.hpp>

#include <neb/fnd/net/client/Base.hpp>
#include <neb/fnd/net/msg/test/Text.hpp>

#include <neb/py/net/client/Base.hpp>

typedef neb::py::net::client::Base THIS;

THIS::Base()
{
}
THIS::Base(W w):
	O(w)
{
}
void		THIS::send(std::string text)
{
	auto c = get_object();
	
	typedef neb::fnd::net::msg::test::Text M;
	
	//std::shared_ptr<M> m(new M, gal::stl::deleter<M>());
	std::shared_ptr<M> m(new M);
	
	m->_M_text = text;

	c->send(m);
}
void		THIS::export_class()
{
	auto c = boost::python::class_<THIS>("client");

	c.def("send", &THIS::send);
}

