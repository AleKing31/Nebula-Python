#ifndef NEB_PY_CORE_GAME_GAME_DESC_HPP
#define NEB_PY_CORE_GAME_GAME_DESC_HPP

#include <boost/python.hpp>

#include <neb/fnd/game/game/desc.hpp>

//#include <neb/py/core/actor/Base.hpp>

namespace neb { namespace py { namespace game { namespace game {
	class Desc:
		public neb::fnd::game::game::desc
	{
		public:
			Desc();
			Desc(Desc const &);
			static void				export_class();
			//void					set_net_type(boost::python::object);
	};
}}}}

#endif

