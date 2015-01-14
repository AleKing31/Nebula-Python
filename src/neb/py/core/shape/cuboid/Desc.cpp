
#include <boost/python.hpp>
namespace bp = boost::python;

#include <neb/py/core/shape/cuboid/Desc.hpp>

typedef neb::py::core::shape::cuboid::Desc THIS;

THIS::Desc()
{
}
THIS::Desc(THIS const & d)
{
}
THIS::Desc(float sx, float sy, float sz):
	neb::core::core::shape::cuboid::Desc(glm::vec3(sx,sy,sz))
{
}
void		THIS::export_class()
{
	auto c = bp::class_<THIS>("Desc", bp::init<float,float,float>());
}

