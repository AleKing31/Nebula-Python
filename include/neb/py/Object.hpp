#ifndef NEB_PY_OBJECT_HPP
#define NEB_PY_OBJECT_HPP

#include <memory>

namespace neb { namespace py {
	template<typename T>
	class Object
	{
	public:
		typedef std::shared_ptr<T> S;
		typedef std::weak_ptr<T> W;
		Object()
		{
		}
		Object(S s):
			_M_object(s)
		{
		}
		Object(W w):
			_M_object(w)
		{
		}
		S			get_object()
		{
			auto s = _M_object.lock();
			assert(s);
			return s;
		}
	private:
		W			_M_object;
	};
}}

#endif
