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
			boost::python::object			createScene();
			boost::python::object			createSceneDll(boost::python::object&);
		private:
			std::weak_ptr<neb::core::app::base>	app_;
	};
}}}

#endif
