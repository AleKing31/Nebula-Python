#ifndef NEB_PY_APP_BASE
#define NEB_PY_APP_BASE

#include <boost/python.hpp>

#include <neb/core/util/decl.hpp>


namespace neb { namespace py { namespace app {
	/***/
	class Base
	{
		public:
			Base(std::shared<neb::core::app::Base>);
			boost::python::object			createWindow();
			boost::python::object			createGame();
			boost::python::object			createLayout(
					boost::python::object& window,
					boost::python::object& context);
			boost::python::object			createScene();
			boost::python::object			createSceneDLL(boost::python::object&);
			boost::python::list			getScenes();
			void					export_class();
			std::weak_ptr<neb::core::app::base>	_M_weak_app;
	};
}}}

#endif
