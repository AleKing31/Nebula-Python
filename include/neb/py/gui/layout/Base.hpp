#ifndef NEB_PY_GUI_LAYOUT_BASE
#define NEB_PY_GUI_LAYOUT_BASE

#include <boost/python.hpp>

#include <neb/fnd/util/decl.hpp>

namespace neb { namespace py { namespace gui { namespace layout {
	class Base {
		public:
			static void		export_class();
			Base();
			Base(std::weak_ptr<neb::fnd::gui::layout::Base>);

			/*
			boost::python::object		createActorRigidDynamic();
			boost::python::object		createActorRigidStaticCube(
					boost::python::object& pose,
					boost::python::object& size);
					*/
		private:
			std::weak_ptr<neb::fnd::gui::layout::Base>		layout_;
	};
}}}}

#endif


