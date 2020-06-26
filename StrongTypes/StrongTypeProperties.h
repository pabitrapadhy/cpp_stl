#pragma once

#include <ostream>
#include "StrongType.h"

template <typename Strong_Type>
struct Addable : public CRTP<Strong_Type, Addable> {
public:
    Strong_Type operator + (Strong_Type& other) const {
        return Strong_Type(this->GetUnderlyingType().get() + other.get());
    }
};

template <typename Strong_Type>
struct Printable : public CRTP<Strong_Type, Printable> {
public:
    void Print(std::ostream& stream) const {
        stream << this->GetUnderlyingType().get();
    }
};

template <typename Strong_Type>
std::ostream& operator << (std::ostream& stream, Printable<Strong_Type> const& other) {
    other.Print(stream);
    return stream;
}

template <typename Strong_Type>
struct Comparable : public CRTP<Strong_Type, Comparable> {
public:
    bool operator < (Strong_Type const& other) const {
        return this->GetUnderlyingType().get() < other.get();
    }
    bool operator > (Strong_Type const& other) const {
        return this->GetUnderlyingType().get() > other.get();
    }
    bool operator <= (Strong_Type const& other) const {
        return this->GetUnderlyingType().get() <= other._value;
    }
    bool operator >= (Strong_Type const& other) const {
        return this->GetUnderlyingType().get() >= other._value;
    }
    bool operator == (Strong_Type const& other) const {
        return this->GetUnderlyingType().get() == other._value;
    }
    bool operator != (Strong_Type const& other) const {
        return this->GetUnderlyingType().get() != other._value;
    }
};