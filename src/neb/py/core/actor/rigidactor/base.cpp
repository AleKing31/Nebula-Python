#include <neb/py/core/actor/rigidactor/base.hpp>
#include <neb/py/core/shape/cuboid/Desc.hpp>
#include <neb/py/core/shape/base.hpp>
#include <neb/core/core/actor/rigidactor/base.hpp>
#include <neb/core/core/shape/base.hpp>

typedef neb::py::core::actor::rigidactor::base THIS;

THIS::base()
{
	assert(0);
}
THIS::base(std::weak_ptr<CORE_TYPE> p):
	rigidactor_(p)
{
}
bp::object		THIS::createShapeCuboid(
		boost::python::object& desc_obj)
{
	typedef neb::py::core::shape::cuboid::Desc T;

	auto desc = bp::extract<T&>(desc_obj);
	
	auto rigidactor(rigidactor_.lock());
	assert(rigidactor);

	//typedef neb::core::core::shape::cuboid::base S;
	typedef neb::core::core::shape::base S;

	auto shape = std::dynamic_pointer_cast<S>(rigidactor->createShapeCuboid(desc).lock());
	
	neb::py::core::shape::Base py_shape(shape);

	return bp::object(py_shape);

}

