#ifndef NEB_PY_CORE_ACTOR_BASE_HPP
#define NEB_PY_CORE_ACTOR_BASE_HPP

#include <neb/core/core/actor/util/decl.hpp>

namespace neb { namespace py { namespace core { namespace actor {
	class Base
	{
		public:
			static void					export_class();
			std::weak_ptr<neb::fnd::core::actor::base>	_M_actor;
	};
}}}}

#endif
