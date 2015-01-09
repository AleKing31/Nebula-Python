#ifndef NEB_PY_CORE_SHAPE_BASE
#define NEB_PY_CORE_SHAPE_BASE

#include <boost/python.hpp>
namespace bp = boost::python;

#include <neb/core/core/shape/util/decl.hpp>

namespace neb { namespace py { namespace core { namespace shape {
	class Base
	{
		public:
			typedef neb::core::core::shape::base CORE_TYPE;
			Base();
			Base(std::weak_ptr<CORE_TYPE>);
		protected:
			std::weak_ptr<CORE_TYPE>	shape_;
	};
}}}}

#endif


