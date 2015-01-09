#ifndef NEB_PY_CORE_ACTOR_RIGID_ACTOR_BASE
#define NEB_PY_CORE_ACTOR_RIGID_ACTOR_BASE

#include <boost/python.hpp>
namespace bp = boost::python;

#include <neb/core/core/actor/util/decl.hpp>


namespace neb { namespace py { namespace core { namespace actor { namespace rigidactor {

	class base
	{
		public:
			//static void		export_class();
			bp::object		createShapeCuboid(
					boost::python::object& desc);
		protected:
			std::weak_ptr<neb::core::core::actor::rigidactor::base>		rigidactor_;
	};
}}}}}

#endif


