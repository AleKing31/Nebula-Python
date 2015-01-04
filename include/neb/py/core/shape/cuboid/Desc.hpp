#ifndef NEB_PY_CORE_SHAPE_CUBOID_DESC_HPP
#define NEB_PY_CORE_SHAPE_CUBOID_DESC_HPP

#include <neb/core/core/shape/cuboid/desc.hpp>

void export_shape_cuboid_desc();

namespace neb { namespace py { namespace core { namespace shape { namespace cuboid {

	class Desc: public neb::core::core::shape::cuboid::Desc
	{
		public:
			static void	export();

			Desc(float sx, float sy, float sz);


	};

}}}}}

#endif
