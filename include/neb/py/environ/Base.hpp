#ifndef NEB_PY_ENVIRON_BASE
#define NEB_PY_ENVIRON_BASE

#include <boost/python.hpp>

#include <neb/fnd/environ/util/decl.hpp>

#include <neb/py/environ/util/decl.hpp>

namespace neb { namespace py { namespace environ {
	class Base {
		public:
			static void			export_class();
			Base();
			Base(std::weak_ptr<neb::fnd::environ::Base>);
			virtual ~Base();
			boost::python::object		is_environ_three();
			boost::python::object		is_environ_scene_base();
			//std::auto_ptr<neb::py::environ::Three>	is_environ_three();
	//private:
			std::weak_ptr<neb::fnd::environ::Base>		environ_;
	};
}}}

#endif
