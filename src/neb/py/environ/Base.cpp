#include <neb/fnd/environ/Base.hpp>
#include <neb/fnd/environ/Three.hpp>
#include <neb/fnd/environ/SceneDefault.hpp>

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
void		THIS::export_class()
{
	auto c = boost::python::class_<THIS>("Base");
	c.def("is_environ_three", &THIS::is_environ_three);
	c.def("is_environ_scene_base", &THIS::is_environ_scene_base);
}

