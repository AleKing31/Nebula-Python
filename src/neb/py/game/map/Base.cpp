#include <neb/fnd/game/map/base.hpp>

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
boost::python::list			THIS::getScenes()
{
	boost::python::list l;

	auto map = get_map();
	
	neb::fnd::core::scene::util::parent & p = *map;
	
	for(auto it : p)
	{
		neb::py::core::scene::base ps(it.second.ptr_);
		//ps.scene_ = scene;
		l.append(ps);
	}
	
	return l;
}
boost::python::object			THIS::create_scene()
{
	//auto app = neb::fnd::app::Base::global();
	auto map = get_map();
	
	auto scene = map->createScene();

	return boost::python::object(neb::py::core::scene::base(scene));
}
void			THIS::export_class()
{
	auto c = boost::python::class_<THIS>("Base");
	c.def("spawn_actor", &THIS::spawn_actor);
	c.def("create_scene",	&THIS::create_scene);
	c.def("getScenes",	&THIS::getScenes);
}

