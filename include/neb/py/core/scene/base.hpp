
#include <boost/python.hpp>

void		export_scene();

namespace neb {

	namespace core { namespace scene {
		class base;
	}}

	namespace py { namespace core { namespace scene {

		class base {
			public:
				void						createActorRigidStaticCube(boost::python::object& pose, boost::python::object& size);
				
				
				::std::weak_ptr<neb::core::scene::base>		scene_;

		};


	}

}}}



