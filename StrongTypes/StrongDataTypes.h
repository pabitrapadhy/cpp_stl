#pragma once

#include "StrongType.h"
#include "StrongTypeProperties.h"

using Integer = StrongType<int, struct IntProperties, Addable, Printable, Comparable>;