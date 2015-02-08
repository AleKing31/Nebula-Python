#ifndef NEB_PY_CONTEXT_BASE
#define NEB_PY_CONTEXT_BASE

#include <boost/python.hpp>

#include <neb/core/context/util/decl.hpp>

namespace neb { namespace py { namespace context {
	class Base {
		public:
			static void		export_class();
			Base();
			Base(std::weak_ptr<neb::fnd::context::Base>&);

			/*
			boost::python::object		createActorRigidDynamic();
			boost::python::object		createActorRigidStaticCube(
					boost::python::object& pose,
					boost::python::object& size);
					*/

			
		//private:
			std::weak_ptr<neb::fnd::context::Base>		context_;
	};
}}}

#endif
