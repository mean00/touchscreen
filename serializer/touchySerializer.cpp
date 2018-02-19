

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
    strcat(out,":");
    strcat(out,name);
    
    append(out,one);
    append(out,two);
    append(out,three);
    return true;
}
/**
 */
 bool DeSerializer::deserialize(const char *input, char *kind, char *name, int &args, char **arg)
{
    const char *head=input;
    // at least a :
    const char *cur=strstr(head,":");
    if(!cur)
    {
        return false;
    }
    int l=cur-head;
    strncpy(kind,head,l);
    kind[l]=0;
    head=cur+1;
    
    cur=strstr(head,";");
    if(!cur)
    {
        strcpy(name,head);
        args=0;
        return true;                
    }
    l=cur-head;
    strncpy(name,head,l);
    name[l]=0;
    args=1;
    head=cur+1;
    
    while(strlen(head))
    {
         cur=strstr(head,";");
         if(!cur)
         {
                strcpy(arg[args],head);
                args++;
                return true;        
         }
         // split
         l=cur-head;
         strncpy(arg[args],head,l);
         arg[args][l]=0;            
         arg++;
         head=cur+1;         
    }    
    return true;    
}
