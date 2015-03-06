#ifndef NEB_PY_INPUT_SOURCE_HPP
#define NEB_PY_INPUT_SOURCE_HPP

#include <neb/py/Object.hpp>

namespace neb { namespace py { namespace input {
	class source:
		public neb::py::Object<neb::fnd::input::source>
	{
		public:
			typedef neb::py::Object<neb::fnd::input::source> O;
			source();
			source(S s);
	};
}}}

#endif
