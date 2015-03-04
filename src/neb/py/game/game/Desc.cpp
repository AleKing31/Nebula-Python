#include <neb/fnd/game/game/desc.hpp>

#include <neb/py/game/game/Desc.hpp>

typedef neb::py::game::game::Desc THIS;

THIS::Desc()
{
}
THIS::Desc(THIS const &)
{
}

/*
THIS::Desc(std::weak_ptr<FND_TYPE> desc):
	_M_desc(desc)
{
}
std::shared_ptr<THIS::FND_TYPE>		THIS::get_desc()
{
	auto d = _M_desc.lock();
	assert(d);
	return d;
}
void					THIS::set_net_type(boost::python::object obj)
{
	int i = boost::python::extract<int>(obj);
	
	auto d = get_desc();
	
	d->_M_net_type = i;
}
*/
void					THIS::export_class()
{
	auto c = boost::python::class_<THIS>("Desc");
	
	c.def_readwrite("net_type", &THIS::_M_net_type);
}

