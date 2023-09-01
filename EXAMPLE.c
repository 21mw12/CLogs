#include <stdio.h>
#include "clogs.h"

int main(void) {
    clogs_Init(LOG_LEVEL_NOTICE, "system.log");

    clogs_WriteLog(LOG_LEVEL_NONE, "这是一条空日志");
    clogs_WriteLog(LOG_LEVEL_INFO, "这是一条信息日志");
    clogs_WriteLog(LOG_LEVEL_HINT, "这是一条提醒日志");
    clogs_WriteLog(LOG_LEVEL_NOTICE, "这是一条注意日志");
    clogs_WriteLog(LOG_LEVEL_WARN, "这是一条警告日志");
    clogs_WriteLog(LOG_LEVEL_ERROR, "这是一条错误日志");

    clogs_Close();

    return 0;
}