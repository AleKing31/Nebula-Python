#include <neb/core/context/Base.hpp>
#include <neb/core/core/scene/base.hpp>

#include <neb/py/core/scene/base.hpp>
#include <neb/py/context/Base.hpp>
#include <neb/py/environ/Base.hpp>

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
	
	auto e = c->get_environ();

	neb::py::environ::Base e_py(e);

	return boost::python::object(e_py);
}
void		THIS::set_drawable(boost::python::object& drawable_object)
{
	auto c = context_.lock();


	// drawable (a scene for now)
	boost::python::extract<neb::py::core::scene::base&> drawable_extract(drawable_object);
	assert(drawable_extract.check());

	auto drawable_python = drawable_extract();

	auto drawable = drawable_python.get_scene();

	c->setDrawable(drawable);
}
void		THIS::export_class()
{
	auto c = boost::python::class_<THIS>("Base");
	c.def("get_environ", &THIS::get_environ);
	c.def("set_drawable", &THIS::set_drawable);
}

