#ifndef NEB_PY_CORE_ACTOR_RIGIDDYNAMIC_DESC_HPP
#define NEB_PY_CORE_ACTOR_RIGIDDYNAMIC_DESC_HPP

#include <neb/core/core/actor/util/decl.hpp>

namespace neb { namespace py { namespace core { namespace actor { namespace rigiddynamic {
	class Desc
	{
	public:
		typedef neb::core::core::actor::rigiddynamic::Desc CORE_TYPE;

		Desc();
		Desc(Desc&&);
		Desc(std::weak_ptr<CORE_TYPE>);
	};
}}}}}

#endif
