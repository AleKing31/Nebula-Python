#include <cstdio>

#include <neb/fnd/game/game/base.hpp>
#include <neb/fnd/game/map/base.hpp>

#include <neb/py/game/game/Base.hpp>
#include <neb/py/game/map/Base.hpp>
#include <neb/py/core/scene/base.hpp>

typedef neb::py::game::game::Base THIS;

THIS::Base()
{
}
THIS::Base(std::weak_ptr<CORE_TYPE> game):
	_M_game(game)
{
}
std::shared_ptr<THIS::CORE_TYPE>	THIS::get_game()
{
	auto g = _M_game.lock();
	assert(g);
	return g;
}
boost::python::object			THIS::create_map_dll(boost::python::object& o)
{
	//auto app = neb::fnd::app::Base::global();
	auto game = get_game();

	// extract string
	char* s = boost::python::extract<char*>(o);
	std::string str(s);

	auto map = game->create_map_dll(str);

	return boost::python::object(neb::py::game::map::Base(map));
}
void			THIS::export_class()
{
	auto c = boost::python::class_<THIS>("Base");
	c.def("create_map_dll", &THIS::create_map_dll);
}


