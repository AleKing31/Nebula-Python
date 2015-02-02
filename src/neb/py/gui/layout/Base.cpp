#include <neb/py/gui/layout/Base.hpp>

typedef neb::py::gui::layout::Base THIS;

void			THIS::export_class()
{
	auto c = boost::python::class_<THIS>("layout");
	//c.def("createActorRigidStaticCube", &neb::py::core::scene::base::createActorRigidStaticCube);
	//c.def("createActorRigidDynamic", &neb::py::core::scene::base::createActorRigidDynamic);
}
THIS::Base()
{
}
THIS::Base(std::weak_ptr<neb::core::gui::layout::Base> layout)
{
	layout_ = layout;
}

