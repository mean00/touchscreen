

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
/**
 */
bool Serializer::serialize(char *out,const char *kind, const char *name,const char *one, const char *two)
{
    return Serializer::serialize(out,kind,name,one,two,NULL);
}
/**
 */
bool Serializer::serialize(char *out,const char *kind, const char *name,const char *one, const char *two, const char *three)
{
    strcpy(out,kind);    
    append(out,name);
    append(out,one);
    append(out,two);
    append(out,three);
    return true;
}
/**
 */
 bool DeSerializer::deserialize( char *input,  int &args, const char **arg)
{
    char *head=input;  
    char *cur;
    args=0;
    while(strlen(head))
    {
         cur=strstr(head,";");
         if(!cur)
         {
                arg[args]=head;
                args++;
                return true;        
         }
         // split
         *cur=0;
         arg[args]=head;
         args++;
         head=cur+1;         
    }    
    return true;    
}
