
#include <boost/python.hpp>

#include <neb/core/app/__base.hpp>
//#include <neb/core/app/__core.hpp>

#include <neb/py/core/scene/base.hpp>
#include <neb/py/app/base.hpp>

typedef neb::py::app::base THIS;

boost::python::object			THIS::createWindow()
{
	auto app = neb::core::app::base::global();

	auto window = app->createWindow();
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
void		export_app()
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





