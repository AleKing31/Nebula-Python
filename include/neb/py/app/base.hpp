#ifndef NEB_PY_APP_BASE
#define NEB_PY_APP_BASE

#include <boost/python.hpp>

#include <neb/core/util/decl.hpp>

void		export_app();

namespace neb { namespace py { namespace app {
	/***/
	class base
	{
		public:
			static boost::python::object			createWindow();
			static boost::python::object			createGame();

			static boost::python::object			createLayout(boost::python::object&, boost::python::object&);
			static boost::python::object			createScene();
			static boost::python::object			createSceneDLL(boost::python::object&);

			static boost::python::list			getScenes();
		public:
			std::weak_ptr<neb::core::app::base>		app_;
	};
}}}

#endif
