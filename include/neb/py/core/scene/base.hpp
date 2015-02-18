#ifndef NEB_PY_CORE_SCENE_BASE
#define NEB_PY_CORE_SCENE_BASE

#include <boost/python.hpp>

#include <neb/core/core/scene/util/decl.hpp>

namespace neb { namespace py { namespace core { namespace scene {
	class base {
		public:
			static void		export_class();
			typedef neb::fnd::core::scene::base FND_TYPE;
			base();
			base(std::weak_ptr<FND_TYPE>);
			boost::python::object		createLightPoint();
			boost::python::object		createActorRigidDynamic();
			boost::python::object		createActorRigidDynamicCuboid();
			boost::python::object		createActorRigidStaticCube(
					boost::python::object& pose,
					boost::python::object& size);
			std::shared_ptr<FND_TYPE>	get_scene();
		private:
			std::weak_ptr<FND_TYPE>		_M_scene;
	};
}}}}

#endif


