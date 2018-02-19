

#include "touchySerializer.h"

static void append(char *out,const char *s)
{
    if(s)
    {
        strcat(out,";");
        strcat(out,s);
    }
}
bool Serializer::serialize(char *out,const char *kind, const char *name)
{
    return Serializer::serialize(out,kind,name,NULL,NULL,NULL);
}

bool Serializer::serialize(char *out,const char *kind, const char *name,const char *one)
{
    return Serializer::serialize(out,kind,name,one,NULL,NULL);
}

bool Serializer::serialize(char *out,const char *kind, const char *name,const char *one, const char *two)
{
    return Serializer::serialize(out,kind,name,one,two,NULL);
}
bool Serializer::serialize(char *out,const char *kind, const char *name,const char *one, const char *two, const char *three)
{
    strcpy(out,kind);
    strcat(out,":");
    strcat(out,name);
    
    append(out,one);
    append(out,two);
    append(out,three);
}