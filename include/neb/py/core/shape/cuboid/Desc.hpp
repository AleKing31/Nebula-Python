#ifndef NEB_PY_CORE_SHAPE_CUBOID_DESC_HPP
#define NEB_PY_CORE_SHAPE_CUBOID_DESC_HPP

#include <neb/fnd/core/shape/cuboid/desc.hpp>

void export_shape_cuboid_desc();

namespace neb { namespace py { namespace core { namespace shape { namespace cuboid {

	class Desc: public neb::fnd::core::shape::cuboid::Desc
	{
		public:
			static void	export_class();

			Desc();
			Desc(Desc const &);
			Desc(Desc&&);
			Desc(float sx, float sy, float sz);
			Desc&		operator=(Desc const &);


	};

}}}}}

#endif
