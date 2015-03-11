#ifndef NEB_PY_NET_CLIENT_BASE
#define NEB_PY_NET_CLIENT_BASE

#include <boost/python.hpp>

#include <gal/stl/verbosity.hpp>

#include <neb/fnd/net/client/util/decl.hpp>

#include <neb/py/Object.hpp>

namespace neb { namespace py { namespace net { namespace client {
	/***/
	class Base:
		public gal::tmp::Verbosity<neb::py::net::client::Base>,
		public neb::py::Object<neb::fnd::net::client::Base>
	{
	public:
		using gal::tmp::Verbosity<neb::py::net::client::Base>::printv;
		typedef neb::py::Object<neb::fnd::net::client::Base> O;
		Base();
		Base(W w);
		void			send(std::string text);
		static void		export_class();
	};
}}}}

#endif
