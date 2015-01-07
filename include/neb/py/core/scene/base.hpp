#ifndef NEB_PY_CORE_SCENE_BASE
#define NEB_PY_CORE_SCENE_BASE

#include <boost/python.hpp>

namespace bp = boost::python;

#include <neb/core/core/scene/util/decl.hpp>

void		export_scene();

namespace neb { namespace py { namespace core { namespace scene {

	class base {
		public:
			base();
			base(std::weak_ptr<neb::core::core::scene::base>);
			bp::object		createActorRigidDynamic();
			bp::object		createActorRigidStaticCube(
					boost::python::object& pose,
					boost::python::object& size);
		private:
			std::weak_ptr<neb::core::core::scene::base>	scene_;
	};
}}}}

#endif


