#include <neb/py/core/shape/base.hpp>

typedef neb::py::core::shape::Base THIS;

THIS::Base()
{
}
THIS::Base(std::weak_ptr<CORE_TYPE> s):
	shape_(s)
{
}
void	THIS::export_class()
{
	auto c = bp::class_<THIS>("Base");
}

