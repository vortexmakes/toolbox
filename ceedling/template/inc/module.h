/**
 *  \file       Config.h
 *  \brief      Specifies the configurtion module.
 */

/* -------------------------- Development history -------------------------- */
/*
 *  2018.09.06  DaBa  v1.0.00   Initial version
 *  2019.18.02  LeFr  v1.1.00   Reviewed to test it
 */

/* -------------------------------- Authors -------------------------------- */
/*
 *  DaBa  Dario Balina db@vortexmakes.com
 *  LeFr  Leandro Francucci  lf@vortexmakes.com
 */

/* --------------------------------- Notes --------------------------------- */
/* --------------------------------- Module -------------------------------- */
#ifndef __CONFIG_H__
#define __CONFIG_H__

/* ----------------------------- Include files ----------------------------- */
#include "rkhtype.h"
#include "IOStatus.h"

/* ---------------------- External C language linkage ---------------------- */
#ifdef __cplusplus
extern "C" {
#endif

/* --------------------------------- Macros -------------------------------- */
/* -------------------------------- Constants ------------------------------ */
#define IP_LENGTH           23
#define PORT_LENGTH         5

/* ------------------------------- Data types ------------------------------ */
typedef struct Config Config;
struct Config
{
    rui8_t aclimit;
    rui8_t brlimit;
    rui8_t status;
    char ip[IP_LENGTH + 1];
    char port[PORT_LENGTH + 1];
    rui8_t conntime;
    rui8_t totacttime;
    rui8_t gpsttime;
    DigOut digOut;
    rui8_t smptime;
};

/* -------------------------- External variables --------------------------- */
/* -------------------------- Function prototypes -------------------------- */
Config *Config_init(void);
Config *config_read(void);
Config *Config_get(void);
void Config_set(Config *cfg);

/* -------------------- External C language linkage end -------------------- */
#ifdef __cplusplus
}
#endif

/* ------------------------------ Module end ------------------------------- */
#endif

/* ------------------------------ End of file ------------------------------ */
