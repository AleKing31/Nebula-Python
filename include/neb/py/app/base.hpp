#ifndef NEB_PY_APP_BASE
#define NEB_PY_APP_BASE

#include <boost/python.hpp>

#include <neb/core/util/decl.hpp>

namespace neb { namespace py { namespace app {
	/***/
	class Base
	{
		public:
			Base();
			Base(std::shared_ptr<neb::core::app::Base> app);
			boost::python::object			createWindow();
			boost::python::object			createGame();
			boost::python::object			createLayout(
					boost::python::object& window,
					boost::python::object& context);
			boost::python::object			createScene();
			boost::python::object			createSceneDLL(boost::python::object&);
			boost::python::list			getScenes();
			boost::python::list			get_windows();
			static void				export_class();
		private:
			std::weak_ptr<neb::core::app::Base>	_M_weak_app;
	};
}}}

#endif
