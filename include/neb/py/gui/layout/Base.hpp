#ifndef NEB_PY_GUI_LAYOUT_BASE
#define NEB_PY_GUI_LAYOUT_BASE

#include <boost/python.hpp>

#include <neb/core/util/decl.hpp>

namespace neb { namespace py { namespace gui { namespace layout {
	class Base {
		public:
			static void		export_class();
			base();
			base(std::weak_ptr<neb::core::gui::layout::Base>);

			/*
			boost::python::object		createActorRigidDynamic();
			boost::python::object		createActorRigidStaticCube(
					boost::python::object& pose,
					boost::python::object& size);
					*/
		private:
			std::weak_ptr<neb::core::gui::layout::Base>		window_;
	};
}}}}

#endif

