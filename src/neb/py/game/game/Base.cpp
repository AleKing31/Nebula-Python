#include <neb/core/game/game/base.hpp>
#include <neb/core/game/map/base.hpp>

#include <neb/py/game/game/Base.hpp>

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
void			THIS::create_map(boost::python::object& scene_object)
{
	auto game = get_game();
	
	typedef neb::fnd::game::map::Base M;

	auto map = game->create<M>().lock();
}
void			THIS::export_class()
{
	auto c = boost::python::class_<THIS>("Base");
	c.def("add_scene", &THIS::add_scene);
}


