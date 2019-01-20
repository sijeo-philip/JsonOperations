#include <stdio.h>
#include "JSONWriter.h"
#include "JSONParser.h"

struct jWriteControl testJSON;
struct jsonParser testReadJSON;
struct jsonReadToken *jsonPacket;

void jWriteTest();

int main(int argc, char *argv[])
{
    jWriteTest();
    return 0;
}



void jWriteTest()
{
    char buffer[1024];
    unsigned int buflen = 1024;
    int err,i;
    char buffer1[1024]= "[\"array1\", 0.12345, 345, true, null, {\"key1\":\"value1\", \"int\":10}]";

    printf("A JSON object example :\n\n");

    jwOpen(&testJSON, buffer, buflen, JW_OBJECT, JW_COMPACT);

    jwObj_string(&testJSON, "key", "value");
    jwObj_int(&testJSON, "int", 10);
    jwObj_double(&testJSON, "double", 1.265487);
    jwObj_null(&testJSON, "null Thing");
    jwObj_bool(&testJSON, "boolean", 1);
    jwObj_array(&testJSON, "EmptyArray");
    jwEnd(&testJSON);
    jwObj_array(&testJSON, "anArray");
    jwArr_string(&testJSON, "array one");
    jwArr_int(&testJSON, -1);
    jwArr_double(&testJSON, 12.568970);
    jwArr_null(&testJSON);
    jwArr_bool(&testJSON, 0);
    jwArr_object(&testJSON);
        jwObj_string(&testJSON, "objArr1", "value1");
        jwObj_string(&testJSON, "objArr2", "value2");
        jwEnd(&testJSON);
    jwArr_array(&testJSON);
        jwArr_int(&testJSON, 1);
        jwArr_int(&testJSON, 2);
        jwArr_int(&testJSON, 3);
    jwEnd(&testJSON);
    jwEnd(&testJSON);
    jwObj_object(&testJSON, "Empty Object");
    jwEnd(&testJSON);
    jwObj_object(&testJSON, "anObject");
    jwObj_string(&testJSON, "msg", "Object in Object");
    jwObj_string(&testJSON, "msg2", "Object in object 2nd");
    jwEnd(&testJSON);
    jwObj_string(&testJSON, "ObjectEntry", "This is the last one");
    jwClose(&testJSON);

   printf(buffer);
   //printf(buffer1);

    err= JSONStructInit(&testReadJSON, buffer);
    printf("\nThe number of tokens parsed %d \n", testReadJSON.numTokens);
    printf("Buffer initialized for reading \n ");
    printf("The value of error is %d \n", err);
    if(err != JDATA_NOK)
    {
        while(testReadJSON.parserStatus!=JSON_END)
        err = JSONParseData(&testReadJSON);
        printf("The Error code is %d\n", err);
        printf("The Number of Tokens parsed are %d\n", testReadJSON.numTokens);
        printf("The value of key parsed is %s\n", testReadJSON.jData[2].keyValue);
        printf("The value of data parsed is %s\n", testReadJSON.jData[5].jsonValue);
        printf("The Value of Stack Position is %d", testReadJSON.parserStatus);
       jsonPacket = SearchToken(&testReadJSON, "\"anObject\"");
       if(jsonPacket!=NULL)
       {
           printf("Packet Found!!!!\n");
           printf("The Value of the entered key is %s\n", jsonPacket->jsonValue);
       }

    }

}
