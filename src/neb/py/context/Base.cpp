#include <neb/fnd/context/Base.hpp>
#include <neb/fnd/core/scene/Base.hpp>
#include <neb/fnd/environ/SceneDefault.hpp>

#include <neb/py/core/scene/base.hpp>
#include <neb/py/context/Base.hpp>
#include <neb/py/environ/Base.hpp>
#include <neb/py/environ/Scene.hpp>

typedef neb::py::context::Base THIS;

THIS::Base()
{
}
THIS::Base(std::weak_ptr<neb::fnd::context::Base> c):
	context_(c)
{
}
boost::python::object	THIS::get_environ()
{
	auto c(context_.lock());
	assert(c);
	
	
	//auto e = c->get_environ();
	auto e = c->neb::fnd::environ::util::Parent::front();


	neb::py::environ::Base e_py(e);

	return boost::python::object(e_py);
}
void		THIS::export_class()
{
	auto c = boost::python::class_<THIS>("Base");
	c.def("create_environ_scene_default", &THIS::create_environ_scene_default);
	//c.def("get_environ", &THIS::get_environ);
	//c.def("set_drawable", &THIS::set_drawable);
}
boost::python::object		THIS::create_environ_scene_default()
{
	auto c(context_.lock());
	assert(c);

	auto e = c->createEnvironSceneDefault().lock();

	neb::py::environ::Scene e_py(e);

	return boost::python::object(e_py);
}

