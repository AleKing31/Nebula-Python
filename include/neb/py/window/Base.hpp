#ifndef NEB_PY_WINDOW_BASE
#define NEB_PY_WINDOW_BASE

#include <boost/python.hpp>

#include <neb/core/util/decl.hpp>


namespace neb { namespace py { namespace window {
	class Base {
		public:
			static void		export_class();
			base();
			base(std::weak_ptr<neb::core::window::Base>);

			/*
			boost::python::object		createActorRigidDynamic();
			boost::python::object		createActorRigidStaticCube(
					boost::python::object& pose,
					boost::python::object& size);
					*/
		private:
			std::weak_ptr<neb::core::window::Base>		window_;
	};
}}}

#endif


