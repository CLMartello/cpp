# cpp06

## Overview

This project introduced type conversion and casting in C++, focusing on how data can be safely or unsafely converted between different types. It helped me understand how C++ handles low-level type manipulation and how to use different casting operators correctly.

## What I Learned

### C++ Casting Operators

One of the main concepts in this module was explicit type casting.

I learned about the different C++ cast operators:

```
static_cast
reinterpret_cast
dynamic_cast
```


Each cast has a specific purpose, and choosing the right one is important for writing safe and predictable code.

### Static Cast

I learned how to use `static_cast` for safe and predictable conversions.

I learned how to:

```
convert numeric types (int, float, double)
```


This is the most commonly used cast in everyday C++ programming.

### Reinterpret Cast

I learned about `reinterpret_cast`, which allows low-level reinterpretation of memory.

I learned how to:

```
treat a value as a completely different type
work with raw memory representations
understand the risks of unsafe conversions
```


This reinforced how powerful and dangerous low-level casting can be.

### Serialization

Another key concept was serialization and deserialization.

I learned how to:

```
convert pointers to integer types (uintptr_t)
store memory addresses in a portable form
reconstruct original pointers from serialized data
```


This helped me understand how data can be represented outside of its original memory context.

### Dynamic Cast

This module also introduced `dynamic_cast` for runtime type checking.

I learned how to:

```
safely cast pointers or references in polymorphic hierarchies
check type validity at runtime
return nullptr or throw exceptions when casting fails
```

This helped me understand safer polymorphic behavior.


## Final Thoughts

CPP06 builds on previous modules by introducing type casting and low-level type manipulation in C++. It strengthened my understanding of how data types interact in memory and how careful casting is essential for writing safe and reliable programs.
