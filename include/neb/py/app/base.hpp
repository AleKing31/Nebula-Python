#ifndef NEB_PY_APP_BASE
#define NEB_PY_APP_BASE

#include <boost/python.hpp>

#include <neb/fnd/util/decl.hpp>

namespace neb { namespace py { namespace app {
	/***/
	class Base
	{
		public:
			Base();
			Base(std::shared_ptr<neb::fnd::app::Base> app);
			boost::python::object			createWindow();
			boost::python::object			createGame();
			boost::python::object			createLayout(
					boost::python::object& window,
					boost::python::object& environ);
			boost::python::object			create_scene();
			//boost::python::object			create_map_dll(boost::python::object&);
			boost::python::list			getScenes();
			boost::python::list			get_windows();
			static void				export_class();
			//static boost::python::object		get_app();
		private:
			std::weak_ptr<neb::fnd::app::Base>	_M_weak_app;
	};
}}}

#endif
