#ifndef NEB_PY_CORE_ACTOR_RIGID_ACTOR_BASE
#define NEB_PY_CORE_ACTOR_RIGID_ACTOR_BASE

#include <boost/python.hpp>

#include <neb/fnd/core/actor/util/decl.hpp>

#include <neb/py/core/actor/Base.hpp>

namespace neb { namespace py { namespace core { namespace actor { namespace rigidactor {

	class base:
		virtual public neb::py::core::actor::Base
	{
		public:
			typedef neb::fnd::core::actor::rigidactor::base CORE_TYPE;
			static void			export_class();
			base();
			base(std::weak_ptr<CORE_TYPE>);
			std::shared_ptr<CORE_TYPE>	get_rigidactor();
			boost::python::object		createShapeCuboid(
					boost::python::object& desc);
			boost::python::object		createWeaponSimpleProjectile(
					boost::python::object& src_obj,
					boost::python::object& size_obj,
					boost::python::object& damage_obj,
					boost::python::object& velocity_obj);
	};
}}}}}

#endif
