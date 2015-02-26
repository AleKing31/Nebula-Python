#include <neb/fnd/environ/Base.hpp>
#include <neb/fnd/environ/Three.hpp>
#include <neb/fnd/environ/SceneDefault.hpp>
#include <neb/fnd/core/scene/Base.hpp>
#include <neb/py/core/scene/base.hpp>
#include <neb/py/environ/Base.hpp>
#include <neb/py/environ/Three.hpp>
#include <neb/py/environ/Scene.hpp>

typedef neb::py::environ::Base THIS;

THIS::Base()
{
}
THIS::~Base()
{
}
THIS::Base(std::weak_ptr<neb::fnd::environ::Base> c):
	environ_(c)
{
}
boost::python::object		THIS::is_environ_three()
{
	auto e_base = environ_.lock();
	assert(e_base);

	auto e = std::dynamic_pointer_cast<neb::fnd::environ::Three>(e_base);
	
	if(e) {
		return boost::python::object(neb::py::environ::Three(e));
	}
	return boost::python::object();
}
boost::python::object		THIS::is_environ_scene_base()
{
	auto e_base = environ_.lock();
	assert(e_base);

	auto e = std::dynamic_pointer_cast<neb::fnd::environ::SceneDefault>(e_base);
	
	if(e) {
		return boost::python::object(neb::py::environ::Scene(e));
	}
	return boost::python::object();
}
void		THIS::set_drawable(boost::python::object& drawable_object)
{
	auto e = environ_.lock();

	// drawable (a scene for now)
	boost::python::extract<neb::py::core::scene::base&> drawable_extract(drawable_object);
	assert(drawable_extract.check());

	auto drawable_python = drawable_extract();

	auto drawable = drawable_python.get_scene();

	e->set_drawable(drawable);
}

void		THIS::export_class()
{
	auto c = boost::python::class_<THIS>("Base");
	c.def("set_drawable", &THIS::set_drawable);
	c.def("is_environ_three", &THIS::is_environ_three);
	c.def("is_environ_scene_base", &THIS::is_environ_scene_base);
}

