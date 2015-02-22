#ifndef NEB_PY_ENVIRON_SCENE_HPP
#define NEB_PY_ENVIRON_SCENE_HPP

#include <boost/python.hpp>

#include <neb/fnd/environ/util/decl.hpp>

#include <neb/py/environ/Three.hpp>

namespace neb { namespace py { namespace environ {
	class Scene:
		virtual public neb::py::environ::Three
	{
		public:
			static void			export_class();
			Scene();
			Scene(std::weak_ptr<neb::fnd::environ::SceneDefault>);
			boost::python::object		create_view_ridealong(boost::python::object& actor_object);
	};
}}}

#endif
