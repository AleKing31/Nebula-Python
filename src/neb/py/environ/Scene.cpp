#include <neb/core/environ/SceneDefault.hpp>

#include <neb/py/environ/Scene.hpp>
#include <neb/py/core/actor/Base.hpp>

typedef neb::py::environ::Scene THIS;

THIS::Scene()
{
}
THIS::Scene(std::weak_ptr<neb::fnd::environ::SceneDefault> e):
	neb::py::environ::Base(e)
{
}
boost::python::object	THIS::create_view_ridealong(boost::python::object& actor_object)
{
	auto e_base = environ_.lock();
	assert(e_base);

	auto e = std::dynamic_pointer_cast<neb::fnd::environ::SceneDefault>(e_base);
	assert(e);

	// actor
	boost::python::extract<neb::py::core::actor::Base&> actor_extract(actor_object);
	assert(actor_extract.check());
	
	auto actor_python = actor_extract();

	auto actor = actor_python._M_actor;

	e->create_view_ridealong(actor);

	return boost::python::object();
}
void		THIS::export_class()
{
	auto c = boost::python::class_<THIS, boost::python::bases<neb::py::environ::Three>>("Scene");
	c.def("create_view_ridealong", &THIS::create_view_ridealong);
}
