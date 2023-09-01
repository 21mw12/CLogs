#ifndef __CLOGS_H__
#define __CLOGS_H__

///////////////////////////////////////////////////////////
//
// �ļ����ܣ�C������־����
// �汾��V1.0
// ���ߣ�īε��MW��
// �޸�ʱ�䣺2023/09/01
//
///////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "color.h"

/* ��־���ݴ�С */
#define MAX_CONTENT     256
/* ��ͬ��־�ȼ���Ӧ�Ĵ�ӡ��ɫ */
#define LOG_ERROR_COLOR    RED
#define LOG_WARN_COLOR     MAGENTA
#define LOG_NOTICE_COLOR   YELLOW
#define LOG_HINT_COLOR     GREEN
#define LOG_INFO_COLOR     BLUE
#define LOG_NONE_COLOR     WHITE

typedef enum LOG_LEVEL{
    LOG_LEVEL_NONE = 0,   // ��
    LOG_LEVEL_INFO,       // ��Ϣ����
    LOG_LEVEL_HINT,       // ��������
    LOG_LEVEL_NOTICE,     // ע�� (Ĭ�Ͼ���ȼ�)
    LOG_LEVEL_WARN,       // ����
    LOG_LEVEL_ERROR,      // ����
} LOG_LEVEL;

typedef struct CLOGS{
    LOG_LEVEL log_Level;
    char* log_FileName;
    FILE* log_File;
} CLOGS;

/**
 * @brief ��־ϵͳ��ʼ��
 * @param write_Level д��ȼ�
 * @param log_FileName ��־�ļ������Ƽ���.logΪ��չ����
 */
void clogs_Init(LOG_LEVEL writeLevel, char* logFileName);

/**
 * @brief �ͷ���־ϵͳ��Դ
 */
void clogs_Close(void);

/**
 * @brief ������־����
 */
void clogs_Clear(void);

/**
 * @brief д��һ����־��Ϣ
 * @param newLogLevel ��ǰ��־�ȼ�
 * @param logContent ��־����
 * @return char* ��ʽ�������־��ʽ
 */
char* clogs_WriteLog(LOG_LEVEL newLogLevel, char* logContent);

#endif
