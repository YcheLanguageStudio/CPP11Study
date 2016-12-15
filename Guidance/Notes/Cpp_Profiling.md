#C++性能Profiling
##Content
###Intro
cache locality, memory alignment, cache associativity, (false) sharing , vectorization, branch prediction, denomals 都都来自于硬件，而不是programming language

###Cache Locality
- 2d array
- struct related
```cpp
class Baz
{
	Foo foo;
	Bar bar;
}

std::vector<Baz> bazs(1000);

doSomething(bazs[i]);
```
- L1 cache: data cache, instruction cache

###Memory Alignment
- packed structs(if not aligned, require to do bit-wise operation)
```cpp
struct Foo
{
	char c;
	short s;
	int i;
	double d;
}
__attribute__((pack));
```
- benchmark: comparing the aligned struct with packed struct

- cast between different memroy alignments
```cpp
struct Foo{

}
```
- could use union
```cpp
union Foo{
	char c[8];
	double d;
}
```

- overalignment
```cpp
struct alignas (32) Foo{
}
```

- alignment on the heap
```cpp

```
- `new` synatx(`std::max_align_T` since c++11)

- convince the phone align does not wrok
```cpp
struct alignas (8) Foo
{
	char ch;
}
auto* a = new Foo;
```

- c++11 introduction`aligned_storage`, `aligned_union`, not work on heap

- use `std::align` is messy

- many use operating system specific system call, but c++ standard not support yet

- align to cache lines, to avoid extracting two cache lines

###False-Sharing

###Cache-Associativity

###Vectorization & Simd
- simd instruction -> CPU <-> Simd Registers
- Auto-vectoriser, `-O3`
- Simd library
```cpp
Vec4<float> a;
a* =f;
```
- SSE intrinsics(not portable)
```cpp

```
- inline assembly
```cpp

```

- how to tell the compiler the pointer is aligned


##References
- [YouTube Vidio by Tgimur Doumler](https://www.youtube.com/watch?v=c-hZpChQKe0&t=201s)
