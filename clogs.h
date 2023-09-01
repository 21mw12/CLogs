#ifndef __CLOGS_H__
#define __CLOGS_H__

///////////////////////////////////////////////////////////
//
// 文件功能：C语言日志功能
// 版本：V1.0
// 作者：墨蔚（MW）
// 修改时间：2023/09/01
//
///////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "color.h"

/* 日志内容大小 */
#define MAX_CONTENT     256
/* 不同日志等级对应的打印颜色 */
#define LOG_ERROR_COLOR    RED
#define LOG_WARN_COLOR     MAGENTA
#define LOG_NOTICE_COLOR   YELLOW
#define LOG_HINT_COLOR     GREEN
#define LOG_INFO_COLOR     BLUE
#define LOG_NONE_COLOR     WHITE

typedef enum LOG_LEVEL{
    LOG_LEVEL_NONE = 0,   // 无
    LOG_LEVEL_INFO,       // 信息内容
    LOG_LEVEL_HINT,       // 可能有误
    LOG_LEVEL_NOTICE,     // 注意 (默认警告等级)
    LOG_LEVEL_WARN,       // 警告
    LOG_LEVEL_ERROR,      // 错误
} LOG_LEVEL;

typedef struct CLOGS{
    LOG_LEVEL log_Level;
    char* log_FileName;
    FILE* log_File;
} CLOGS;

/**
 * @brief 日志系统初始化
 * @param write_Level 写入等级
 * @param log_FileName 日志文件名（推荐以.log为扩展名）
 */
void clogs_Init(LOG_LEVEL writeLevel, char* logFileName);

/**
 * @brief 释放日志系统资源
 */
void clogs_Close(void);

/**
 * @brief 清理日志内容
 */
void clogs_Clear(void);

/**
 * @brief 写入一个日志信息
 * @param newLogLevel 当前日志等级
 * @param logContent 日志内容
 * @return char* 格式化后的日志格式
 */
char* clogs_WriteLog(LOG_LEVEL newLogLevel, char* logContent);

#endif
