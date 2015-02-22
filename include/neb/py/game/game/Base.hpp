#ifndef NEB_PY_CORE_GAME_GAME_BASE_HPP
#define NEB_PY_CORE_GAME_GAME_BASE_HPP

#include <boost/python.hpp>

#include <neb/fnd/game/game/util/decl.hpp>

//#include <neb/py/core/actor/Base.hpp>

namespace neb { namespace py { namespace game { namespace game {
	class Base
	{
		public:
			typedef neb::fnd::game::game::base CORE_TYPE;
			static void			export_class();
			Base();
			Base(std::weak_ptr<CORE_TYPE>);
			std::shared_ptr<CORE_TYPE>	get_game();
			boost::python::object		create_map_dll(boost::python::object& string_object);
		protected:
			std::weak_ptr<CORE_TYPE>		_M_game;
	};
}}}}

#endif

