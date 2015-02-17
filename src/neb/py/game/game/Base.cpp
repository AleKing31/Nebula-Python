#include <neb/py/game/game/Base.hpp>

typedef neb::py::game::game::Base THIS;

THIS::Base()
{
}
THIS::Base(std::weak_ptr<CORE_TYPE> game):
	_M_game(game)
{
}
void			THIS::add_scene(boost::python::object& scene_object)
{
}
void			THIS::export_class()
{
	auto c = boost::python::class_<THIS>("Base");
	c.def("add_scene", &THIS::add_scene);
}


