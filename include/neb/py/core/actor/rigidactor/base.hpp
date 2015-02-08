#ifndef NEB_PY_CORE_ACTOR_RIGID_ACTOR_BASE
#define NEB_PY_CORE_ACTOR_RIGID_ACTOR_BASE

#include <boost/python.hpp>
namespace bp = boost::python;

#include <neb/core/core/actor/util/decl.hpp>


namespace neb { namespace py { namespace core { namespace actor { namespace rigidactor {

	class base
	{
		public:
			typedef neb::fnd::core::actor::rigidactor::base CORE_TYPE;
			//static void		export_class();
			bp::object		createShapeCuboid(
					boost::python::object& desc);
			base();
			base(std::weak_ptr<CORE_TYPE>);
		protected:
			std::weak_ptr<CORE_TYPE>		rigidactor_;
	};
}}}}}

#endif


