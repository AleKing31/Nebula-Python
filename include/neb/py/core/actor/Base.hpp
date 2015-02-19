#ifndef NEB_PY_CORE_ACTOR_BASE_HPP
#define NEB_PY_CORE_ACTOR_BASE_HPP

#include <neb/core/core/actor/util/decl.hpp>

namespace neb { namespace py { namespace core { namespace actor {
	class Base
	{
		public:
			typedef neb::fnd::core::actor::base		CORE_TYPE;
			Base();
			Base(std::weak_ptr<CORE_TYPE> actor);
			std::shared_ptr<CORE_TYPE>			get_actor();
			static void					export_class();
			std::weak_ptr<CORE_TYPE>			_M_actor;
	};
}}}}

#endif
