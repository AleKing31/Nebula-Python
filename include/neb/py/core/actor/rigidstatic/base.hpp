#ifndef NEB_PY_CORE_ACTOR_RIGID_STATIC_BASE
#define NEB_PY_CORE_ACTOR_RIGID_STATIC_BASE

#include <boost/python.hpp>

#include <neb/core/core/actor/util/decl.hpp>
#include <neb/py/core/actor/rigidactor/base.hpp>

namespace neb { namespace py { namespace core { namespace actor { namespace rigidstatic {

	class base:
		public neb::py::core::actor::rigidactor::base
	{
		public:
			static void		export_class();
			base();
			base(std::weak_ptr<neb::fnd::core::actor::rigidstatic::base>);
	};
}}}}}

#endif


