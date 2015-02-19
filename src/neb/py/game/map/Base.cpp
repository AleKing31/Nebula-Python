#include <neb/core/game/map/base.hpp>

#include <neb/py/core/actor/Base.hpp>
#include <neb/py/core/scene/base.hpp>
#include <neb/py/game/map/Base.hpp>

typedef neb::py::game::map::Base THIS;

THIS::Base()
{
}
THIS::Base(std::weak_ptr<CORE_TYPE> map):
	_M_map(map)
{
}
std::shared_ptr<THIS::CORE_TYPE>	THIS::get_map()
{
	auto g = _M_map.lock();
	assert(g);
	return g;
}
void			THIS::set_scene(boost::python::object& scene_object)
{
	// get scene
	boost::python::extract<neb::py::core::scene::base&> scene_extract(scene_object);
	assert(scene_extract.check());

	auto scene_python = scene_extract();

	auto scene = scene_python.get_scene();

	// get map
	auto map = get_map();

	// do stuff
	map->set_scene(scene);

	map->setup();
}
void			THIS::spawn_actor(boost::python::object& actor_object)
{
	// get scene
	boost::python::extract<neb::py::core::actor::Base&> actor_extract(actor_object);
	assert(actor_extract.check());

	auto actor_python = actor_extract();

	auto actor = actor_python.get_actor();

	// do stuff
	get_map()->spawn_actor(actor);
}
void			THIS::export_class()
{
	auto c = boost::python::class_<THIS>("Base");
	c.def("set_scene", &THIS::set_scene);
	c.def("spawn_actor", &THIS::spawn_actor);
}

