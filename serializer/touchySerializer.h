

#pragma once
#include <string.h>
class Serializer
{
public:
    static bool serialize(char *out,const char *kind, const char *name);
    static bool serialize(char *out,const char *kind, const char *name,const char *one);
    static bool serialize(char *out,const char *kind, const char *name,const char *one, const char *two);
    static bool serialize(char *out,const char *kind, const char *name,const char *one, const char *two, const char *three);
    
};