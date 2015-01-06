#ifndef NEB_PY_CORE_ACTOR_RIGID_DYNAMIC_BASE
#define NEB_PY_CORE_ACTOR_RIGID_DYNAMIC_BASE

#include <boost/python.hpp>

#include <neb/core/core/actor/util/decl.hpp>


namespace neb { namespace py { namespace core { namespace actor { namespace rigiddynamic {

	class base
	{
		public:
			static void		export_class();
			base();
			base(std::weak_ptr<neb::core::core::actor::rigiddynamic::base>);
			void			createShapeCuboid(
					boost::python::object& desc);
		private:
			std::weak_ptr<neb::core::core::actor::rigiddynamic::base>	actor_;
	};
}}}}}

#endif


