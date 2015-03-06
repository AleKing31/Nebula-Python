#ifndef NEB_PY_CORE_ACTOR_CONTROL_RIGIDBODY_BASE_HPP
#define NEB_PY_CORE_ACTOR_CONTROL_RIGIDBODY_BASE_HPP

#include <neb/fnd/core/actor/util/decl.hpp>

#include <neb/py/Object.hpp>

#include <neb/py/input/source.hpp>
#include <neb/py/input/js.hpp>

namespace neb { namespace py { namespace core { namespace actor { namespace control { namespace rigidbody {
	class Base:
		public neb::py::Object<neb::fnd::core::actor::control::rigidbody::base>
	{
		public:
			typedef neb::py::Object<neb::fnd::core::actor::control::rigidbody::base> O;
			Base();
			Base(S s);
			void						connect(neb::py::input::source);
			void						connect(neb::py::input::js);
			static void					export_class();
	};
}}}}}}

#endif
