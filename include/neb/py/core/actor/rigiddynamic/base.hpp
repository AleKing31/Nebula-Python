#ifndef NEB_PY_CORE_ACTOR_RIGID_DYNAMIC_BASE
#define NEB_PY_CORE_ACTOR_RIGID_DYNAMIC_BASE

#include <boost/python.hpp>

namespace bp = boost::python;

#include <neb/core/core/actor/util/decl.hpp>

#include <neb/py/core/actor/rigidactor/base.hpp>

namespace neb { namespace py { namespace core { namespace actor { namespace rigiddynamic {

	class base:
		public neb::py::core::actor::rigidactor::base
	{
		public:
			static void		export_class();
			base();
			base(std::weak_ptr<neb::fnd::core::actor::rigiddynamic::base>);
		private:
			std::weak_ptr<neb::fnd::core::actor::rigiddynamic::base>	actor_;
	};
}}}}}

#endif


