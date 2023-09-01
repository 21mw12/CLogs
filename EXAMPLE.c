#include <stdio.h>
#include "clogs.h"

int main(void) {
    clogs_Init(LOG_LEVEL_NOTICE, "system.log");

    clogs_WriteLog(LOG_LEVEL_NONE, "����һ������־");
    clogs_WriteLog(LOG_LEVEL_INFO, "����һ����Ϣ��־");
    clogs_WriteLog(LOG_LEVEL_HINT, "����һ��������־");
    clogs_WriteLog(LOG_LEVEL_NOTICE, "����һ��ע����־");
    clogs_WriteLog(LOG_LEVEL_WARN, "����һ��������־");
    clogs_WriteLog(LOG_LEVEL_ERROR, "����һ��������־");

    clogs_Close();

    return 0;
}