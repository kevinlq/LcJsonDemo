#include <QCoreApplication>
#include <QTextCodec>

#include "cJSON.h"


/**
  解析json个数数据
*/
bool jsonDecode();

/**
  创建json格式数据
*/
bool jsonEncode();

char text[] = "{\"timestamp\":\"2017-09-27T08:50:11\",\"value\":1}";

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextCodec::setCodecForLocale (QTextCodec::codecForName ("UTF-8"));
    QTextCodec::setCodecForCStrings (QTextCodec::codecForName ("UTF-8"));
    QTextCodec::setCodecForTr (QTextCodec::codecForName ("UTF-8"));

    printf ("解析json格式数据:\r\n");
    printf ("json:%s \r\n",text);
    jsonDecode();

    printf ("创建json格式数据:\r\n");

    return a.exec();
}

bool jsonDecode()
{
    cJSON *pJson;
    cJSON *pJsonValue;
    cJSON *pJsonTimestamp;

    pJson = cJSON_Parse (text);
    if ( !pJson ){
        printf ( "Error before:%s\n",cJSON_GetErrorPtr () );
        return false;
    }else{
        pJsonValue = cJSON_GetObjectItem ( pJson,"value" );
        if ( pJsonValue->type == cJSON_Number){
            printf ( "value:%d\r\n",pJsonValue->valueint);
        }

        pJsonTimestamp = cJSON_GetObjectItem ( pJson,"timestamp" );
        if (pJsonTimestamp->type == cJSON_String){
            printf ( "%s\r\n",pJsonTimestamp->valuestring );
        }

        cJSON_Delete(pJson);
    }
    return true;
}

bool jsonEncode()
{
    return true;
}
