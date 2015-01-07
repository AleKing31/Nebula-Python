
#include <boost/python.hpp>
namespace bp = boost::python;

#include <neb/py/core/shape/cuboid/Desc.hpp>

neb::py::core::shape::cuboid::Desc::Desc()
{
}
neb::py::core::shape::cuboid::Desc::Desc(float sx, float sy, float sz):
	neb::core::core::shape::cuboid::Desc(glm::vec3(sx,sy,sz))
{
}
void neb::py::core::shape::cuboid::Desc::export_class()
{
	auto c = bp::class_<neb::py::core::shape::cuboid::Desc>("Desc", bp::init<float,float,float>());
}

