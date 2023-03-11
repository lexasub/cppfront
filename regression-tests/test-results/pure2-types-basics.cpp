
#define CPP2_USE_MODULES         Yes

#include "cpp2util.h"


#line 2 "pure2-types-basics.cpp2"
namespace N   {
class myclass;
};
#line 48 "pure2-types-basics.cpp2"
auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 1 "pure2-types-basics.cpp2"

namespace N   {

class myclass   {

    public: myclass(cpp2::in<int> x)
        : data{ x }
        , more{ "xyzzy" }
#line 7 "pure2-types-basics.cpp2"
{

        std::cout << "myclass: implicit constructor from int\n";
    }

    public: explicit myclass(cpp2::in<std::string> s)
        : data{ 99 }
        , more{ "plugh" }
#line 13 "pure2-types-basics.cpp2"
{

        std::cout << "myclass: explicit constructor from string\n";
    }

    public: myclass()
        : data{ 3 }
        , more{ "-3" }
#line 19 "pure2-types-basics.cpp2"
{

        std::cout << "myclass: default constructor\n";
    }

    public: ~myclass(){
        std::cout << "myclass: destructor\n";
    }

    public: virtual auto f(cpp2::in<int> x) const -> void{
        std::cout << "N::myclass::f with " + cpp2::to_string(x) + "\n";
    }

    private: int data; 
    private: std::string more; 

    public: class nested {
        public: static auto g() -> void { std::cout << "N::myclass::nested::g\n"; }
    };

    public: template<typename T, typename U> [[nodiscard]] static auto f1(T const& t, U const& u) -> auto { return t + u; }
    public: template<typename T, typename U> [[nodiscard]] static auto f2(T const& t, U const& u) -> auto { return t + u; }
    public: template<auto T, auto U> [[nodiscard]] static auto f3() -> auto { return T + U; }
    public: template<cpp2::i8 T, cpp2::i16 U> [[nodiscard]] static auto f4() -> auto { return T + U; }

};

};

auto main() -> int{
    N::myclass x {1}; 
    CPP2_UFCS(f, x, 53);
    N::myclass::nested::g();
    std::cout << "f1: " + cpp2::to_string(CPP2_UFCS(f1, x, 1, 1)) + "\n";
    std::cout << "f2: " + cpp2::to_string(CPP2_UFCS(f2, x, 2, 2)) + "\n";
    std::cout << "f3: " + cpp2::to_string(CPP2_UFCS_TEMPLATE_0(f3, (<3,3>), x)) + "\n";
    std::cout << "f4: " + cpp2::to_string(CPP2_UFCS_TEMPLATE_0(f4, (<4,4>), std::move(x))) + "\n";
    N::myclass x2 {"abracadabra"}; 
    N::myclass x3 {}; 
}
