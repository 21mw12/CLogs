#include "clogs.h"

CLOGS Clogs = {
    LOG_LEVEL_NOTICE,
    NULL,
    NULL
};

time_t tmpcal_ptr;
struct tm *tmp_ptr = NULL;

void clogs_Init(LOG_LEVEL writeLevel, char* logFileName) {
    Clogs.log_Level = writeLevel;
    Clogs.log_FileName = logFileName;
    Clogs.log_File = fopen(logFileName, "a+");
}

void clogs_Close(void) {
    fclose(Clogs.log_File);
}

void clogs_Clear(void) {
    clogs_Close();
    Clogs.log_File = NULL;
    remove(Clogs.log_FileName);
}

char* clogs_GetTime(void) {
    time(&tmpcal_ptr);	
    tmp_ptr = localtime(&tmpcal_ptr);

    char* timeData = (char*) malloc(19);
    sprintf(timeData, "%d.%d.%d %d:%d:%d", (1900+tmp_ptr->tm_year), 
                                            (1+tmp_ptr->tm_mon), 
                                            tmp_ptr->tm_mday, 
                                            tmp_ptr->tm_hour, 
                                            tmp_ptr->tm_min, 
                                            tmp_ptr->tm_sec);
    
    return timeData;
}

char* clogs_WriteLog(LOG_LEVEL newLogLevel, char* logContent) {
    char* content = (char*) malloc(MAX_CONTENT);

    /* 处理不同等级的日志信息并打印出来 */
    switch (newLogLevel) {
        case LOG_LEVEL_NONE:
            sprintf(content, "NONE[%s]: %s\n", clogs_GetTime(), 
                                                logContent);
            printf(LOG_NONE_COLOR"%s"RESET, content);
            break;
        case LOG_LEVEL_INFO:
            sprintf(content, "INFO[%s]: %s\n", clogs_GetTime(), 
                                                logContent);
            printf(LOG_INFO_COLOR"%s"RESET, content);
            break;
        case LOG_LEVEL_HINT:
            sprintf(content, "HINT[%s]: %s\n", clogs_GetTime(), 
                                                logContent);
            printf(LOG_HINT_COLOR"%s"RESET, content);
            break;
        case LOG_LEVEL_NOTICE:
            sprintf(content, "NOTICE[%s]: %s\n", clogs_GetTime(), 
                                                logContent);
            printf(LOG_NOTICE_COLOR"%s"RESET, content);
            break;
        case LOG_LEVEL_WARN:
            sprintf(content, "WARN[%s]: %s\n", clogs_GetTime(), 
                                                logContent);
            printf(LOG_WARN_COLOR"%s"RESET, content);
            break;
        case LOG_LEVEL_ERROR:
            sprintf(content, "ERROR[%s]: %s\n", clogs_GetTime(), 
                                                logContent);
            printf(LOG_ERROR_COLOR"%s"RESET, content);
            break;    
        default:
            break;
    }

    /* 把高于或等于写入等级的日志写入文件 */
    if (newLogLevel >= Clogs.log_Level && Clogs.log_File != NULL) {
        fprintf(Clogs.log_File, content);
    }

    return content;
}
