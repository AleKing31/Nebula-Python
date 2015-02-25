#ifndef NEB_PY_WINDOW_BASE
#define NEB_PY_WINDOW_BASE

#include <boost/python.hpp>

#include <neb/fnd/util/decl.hpp>

namespace neb { namespace py { namespace window {
	class Base {
		public:
			typedef neb::fnd::window::Base T;
			static void				export_class();
			Base();
			Base(std::weak_ptr<neb::fnd::window::Base>);
			boost::python::object			createContextWindow();
			std::shared_ptr<T>			get_window();
		//private:
			std::weak_ptr<T>			window_;
	};
}}}

#endif
