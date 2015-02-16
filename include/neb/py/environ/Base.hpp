#ifndef NEB_PY_ENVIRON_BASE
#define NEB_PY_ENVIRON_BASE

#include <boost/python.hpp>

#include <neb/core/environ/util/decl.hpp>

namespace neb { namespace py { namespace environ {
	class Base {
		public:
			static void			export_class();
			Base();
			Base(std::weak_ptr<neb::fnd::environ::Base>);
			boost::python::object		get_environ();
		//private:
			std::weak_ptr<neb::fnd::environ::Base>		environ_;
	};
}}}

#endif
