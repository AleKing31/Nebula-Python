#ifndef NEB_PY_NET_SERVER_BASE
#define NEB_PY_NET_SERVER_BASE

#include <boost/python.hpp>

#include <gal/stl/verbosity.hpp>

#include <neb/fnd/net/server/util/decl.hpp>
//#include <neb/fnd/net/client/util/decl.hpp>

#include <neb/py/Object.hpp>

namespace neb { namespace py { namespace net { namespace server {
	/***/
	class Base:
		public gal::tmp::Verbosity<neb::py::net::server::Base>,
		public neb::py::Object<neb::fnd::net::server::Base>
	{
	public:
		using gal::tmp::Verbosity<neb::py::net::server::Base>::printv;
		typedef neb::py::Object<neb::fnd::net::server::Base> O;
		Base();
		Base(W w);
		static void			export_class();
	};
}}}}

#endif
