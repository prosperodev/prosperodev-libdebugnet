/*
#  ____   ____   ____      ___  ____   ____  ____   ____  ____   ____ _     _
#  ____|  ____> |    |    |     ____| <____  ____> |    |     | <____  \   /
# |      |    \ |____| ___|    |      <____ |    \ |____| ____| <____   \_/  
# 
# PROSPERODEV Open Source Project.
#------------------------------------------------------------------------------------
# Copyright 2010-2022, prosperodev - http://github.com/prosperodev
# Licenced under MIT License
# Review README & LICENSE files for further details.
*/

#ifndef _PROSPERO_DEBUGNET_H_
#define _PROSPERO_DEBUGNET_H_

#ifdef __cplusplus
extern "C" {
#endif

#define DEBUGNET_NONE 0
#define DEBUGNET_INFO 1
#define DEBUGNET_ERROR 2
#define DEBUGNET_DEBUG 3

typedef struct debugNetConfiguration
{
	int debugnet_initialized;
	int SocketFD;
	int logLevel;
} debugNetConfiguration;

int debugNetInit(char *serverIp, int port, int level);
int debugNetInitWithConf(debugNetConfiguration *conf);
debugNetConfiguration *debugNetGetConf(void);
int debugNetSetConf(debugNetConfiguration *conf);
void debugNetFinish(void);
void debugNetUDPPrintf(const char* fmt, ...);
void debugNetPrintf(int level, char* format, ...);
void debugNetSetLogLevel(int level);
int debugNetCreateConf(void);


#ifdef __cplusplus
}
#endif

#endif
