#pragma once

#include <iostream>
using namespace std;

template <typename Strong_Type, template <typename> class CRTPType>
struct CRTP {
public:
    Strong_Type const& GetUnderlyingType() const {
        return static_cast<Strong_Type const&>(*this);
    }
};

template <typename UnderlyingType, typename PhantomTag, template <typename> class... Skills>
class StrongType : public Skills<StrongType<UnderlyingType, PhantomTag, Skills...>>... {
private:
    UnderlyingType _value;

public:
    explicit StrongType(UnderlyingType value) : _value(value) {}
    UnderlyingType get() const { return _value; }
};