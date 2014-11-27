
#include <boost/python.hpp>

#include <neb/core/app/__base.hpp>
//#include <neb/core/app/__core.hpp>

#include <neb/py/core/scene/base.hpp>
#include <neb/py/app/base.hpp>

typedef neb::py::app::base THIS;

boost::python::object			createScene()
{
	auto app = neb::core::app::__base::global();
	
	auto scene = app->createScene();

	return bp::object(neb::py::core::scene::base(scene));
}
boost::python::object			createSceneDll(boost::python::object& o)
{
	auto app = neb::core::app::__base::global();
	
	char* s = bp::extract<char*>(o);

	std::string str(s);

	auto scene = app->createSceneDLL(str);

	return bp::object(neb::py::core::scene::base(scene));
}
void		export_app()
{
	
	boost::python::def("createScene", createScene);

	//boost::python::class_<neb::py::app::base>("App");
	//	.def("createActorRigidStaticCube", &neb::py::core::scene::base::createActorRigidStaticCube);
	//        .def("greet", &World::greet)
	//       .def("set", &World::set)
	//    ;
}





