
#include <boost/python.hpp>

#include <neb/core/app/__base.hpp>
//#include <neb/core/app/__core.hpp>

#include <neb/py/core/scene/base.hpp>
#include <neb/py/app/base.hpp>
#include <neb/py/window/Base.hpp>
#include <neb/py/context/Base.hpp>
#include <neb/py/gui/layout/Base.hpp>

typedef neb::py::app::base THIS;

THIS::Base(std::shared_ptr<neb::core::app::Base> app):
	_M_weak_app(app)
{
	assert(app);
}
boost::python::object			THIS::createWindow()
{
	auto app = neb::core::app::base::global();

	auto window = app->createWindow();

	neb::py::window::Base pw(window);

	return boost::python::object(pw);
}
boost::python::object			THIS::createLayout(
		boost::python::object& window_obj,
		boost::python::object& context_obj)
{
	auto app = neb::core::app::base::global();

	// window
	auto window_ex = boost::python::extract<neb::py::window::Base&>(window_obj);
	assert(window_ex.check());
	auto window_py = window_ex();

	auto window = window_py.window_.lock();
	assert(window);

	// context
	auto context_ex = boost::python::extract<neb::py::context::Base&>(context_obj);
	assert(context_ex.check());
	auto context_py = context_ex();

	auto context = context_py.context_.lock();
	assert(context);


	auto layout = app->createLayout(window, context);
	
	neb::py::gui::layout::Base layout_py(layout);

	return boost::python::object(layout_py);
}
boost::python::list			THIS::getScenes()
{
	boost::python::list l;
	auto app = neb::core::app::base::global();
	
	neb::core::core::scene::util::parent & p = *app;
	
	for(auto it : p)
	{
		neb::py::core::scene::base ps(it.second.ptr_);
		//ps.scene_ = scene;
		l.append(ps);
	}
	
	return l;
}
boost::python::object			THIS::createScene()
{
	auto app = neb::core::app::base::global();
	
	auto scene = app->createScene();

	return bp::object(neb::py::core::scene::base(scene));
}
boost::python::object			THIS::createSceneDLL(boost::python::object& o)
{
	auto app = neb::core::app::base::global();
	
	char* s = bp::extract<char*>(o);

	std::string str(s);

	auto scene = app->createSceneDLL(str);

	return bp::object(neb::py::core::scene::base(scene));
}
void					THIS::export_class()
{
	boost::python::def("createWindow", THIS::createWindow);
	boost::python::def("createLayout", THIS::createLayout);

	boost::python::def("createScene", THIS::createScene);
	boost::python::def("createSceneDLL", THIS::createSceneDLL);

	boost::python::def("getScenes",   THIS::getScenes);

	//boost::python::class_<neb::py::app::base>("App");
	//	.def("createActorRigidStaticCube", &neb::py::core::scene::base::createActorRigidStaticCube);
	//        .def("greet", &World::greet)
	//       .def("set", &World::set)
	//    ;
}



