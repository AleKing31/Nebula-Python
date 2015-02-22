#ifndef NEB_PY_ENVIRON_THREE_HPP
#define NEB_PY_ENVIRON_THREE_HPP

#include <boost/python.hpp>

#include <neb/fnd/environ/util/decl.hpp>

#include <neb/py/environ/Base.hpp>

namespace neb { namespace py { namespace environ {
	class Three:
		virtual public neb::py::environ::Base
	{
		public:
			static void			export_class();
			Three();
			Three(std::weak_ptr<neb::fnd::environ::Three>);
	};
}}}

#endif
