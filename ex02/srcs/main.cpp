#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main(void)
{
	Base *ptr = generate();
	
	identify(ptr);

	identify(*ptr);
	return (0);
}
