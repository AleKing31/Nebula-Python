#ifndef NEB_PY_INPUT_JS_HPP
#define NEB_PY_INPUT_JS_HPP

#include <neb/fnd/input/util/decl.hpp>

#include <neb/py/Object.hpp>

namespace neb { namespace py { namespace input {
	class js:
		public neb::py::Object<neb::fnd::input::js>
	{
		public:
			typedef neb::py::Object<neb::fnd::input::js> O;
			js();
			js(S s);
	};
}}}

#endif

