#ifndef NEB_PY_CONTEXT_BASE
#define NEB_PY_CONTEXT_BASE

#include <boost/python.hpp>

#include <neb/fnd/context/util/decl.hpp>

namespace neb { namespace py { namespace context {
	class Base {
		public:
			static void			export_class();
			Base();
			Base(std::weak_ptr<neb::fnd::context::Base>);
			boost::python::object		get_environ();
			boost::python::object		create_environ_scene_default();
			//void				set_drawable(boost::python::object& drawable_object);
		//private:
			std::weak_ptr<neb::fnd::context::Base>		context_;
	};
}}}

#endif
