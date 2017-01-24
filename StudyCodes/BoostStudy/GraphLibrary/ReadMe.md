#Boost Graph Module
##Property Map
###Usage Demo
- set value usage

```cpp
property_map<MyGraphType, vertex_first_name_t>::type name = get(vertex_first_name, G);
boost::put(name, 0, "Jeremy");

name[4] = "Kinis"; // you can use operator[] too        
```

- get value usage

```cpp
using NamePA= typename property_map<Graph, vertex_first_name_t>::const_type;
NamePA name = get(vertex_first_name, G);

using NameType=typename boost::property_traits<NamePA>::value_type;
NameType src_name, targ_name;

src_name = boost::get(name, source(*first, G));
targ_name = name[target(*first, G)];        // you can use operator[] too
```