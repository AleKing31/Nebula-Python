#ifndef NEB_PY_APP_BASE
#define NEB_PY_APP_BASE

#include <boost/python.hpp>

#include <gal/stl/verbosity.hpp>

#include <neb/fnd/util/decl.hpp>

#include <neb/py/input/js.hpp>

namespace neb { namespace py { namespace app {
	/***/
	class Base:
		public gal::tmp::Verbosity<neb::py::app::Base>,
		public neb::py::Object<neb::fnd::app::Base>
	{
	public:
		using gal::tmp::Verbosity<neb::py::app::Base>::printv;
		typedef neb::py::Object<neb::fnd::app::Base> O;
		Base();
		Base(S app);
		boost::python::object		create_server(
				int portno);
		boost::python::object		create_client(
				std::string,
				int portno);
		boost::python::object		createWindow();
		boost::python::object		createGame(
				boost::python::object desc_obj);
		boost::python::object		createLayout(
				boost::python::object& window,
				boost::python::object& environ);
		boost::python::list		get_windows();
		static void			export_class();
		boost::python::object		get_joystick(
				int i = -1);
	};
}}}

#endif
