/**
 *  \file       Config.c
 *  \brief      Implements the configurtion module.
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
/* ----------------------------- Include files ----------------------------- */
#include "rkhtype.h"
#include "rkhassert.h"
#include "rkhitl.h"     /* It's needed to include platform files */
#include "Config.h"
#include "settings.h"
#include "ffile.h"
#include "ffdata.h"

RKH_MODULE_NAME(Config)

/* ----------------------------- Local macros ------------------------------ */
/* ------------------------------- Constants ------------------------------- */
static const Config cfgDft =
{
    ACLIMIT_DFT,
    BRLIMIT_DFT,
    1,
    IP_DFT,
    PORT_DFT,
    CONNTIME_DFT,
    TOTACTTIME,
    GPSTTIME,
    DIGOUT_DFT,
    SMPTIME_DFT
};

/* ---------------------------- Local data types --------------------------- */
/* ---------------------------- Global variables --------------------------- */
/* ---------------------------- Local variables ---------------------------- */
static Config cfgObj;       /* It is a shared resource! */

/* ----------------------- Local function prototypes ----------------------- */
/* ---------------------------- Local functions ---------------------------- */
/* ---------------------------- Global functions --------------------------- */
Config *
Config_get(void)
{
    Config *cfg;
    RKH_SR_ALLOC();

    RKH_ENTER_CRITICAL_();
    RKH_ENSURE(cfgObj.status == 1);
    cfg = (Config *)&cfgObj;
    RKH_EXIT_CRITICAL_();
    return cfg;
}

Config *
Config_init(void)
{
    int res;
    Config *cfg;

	ffile_seek(FFD1, 0);
	res = ffile_random_access(FFD1, READ_ACCESS, &cfgObj, 1);
    if (res > 0)
    {
        if (cfgObj.status != 1)
        {
            cfg = (Config *)&cfgDft;
            Config_set(cfg);
        }
        else
        {
            cfg = &cfgObj;
        }
    }
    else
    {
        cfg = (Config *)&cfgDft;
        Config_set(cfg);
    }
    return cfg;
}

void 
Config_set(Config *cfg)
{
    int res;
    RKH_SR_ALLOC();

    RKH_REQUIRE(cfg != (Config *)0);
    RKH_ENTER_CRITICAL_();
	ffile_seek(FFD1, 0);
	res = ffile_random_access(FFD1, WRITE_ACCESS, cfg, 1);
    RKH_ENSURE(res > 0);
    ffile_sync();
    cfgObj = *cfg;
    RKH_EXIT_CRITICAL_();
}

/* ------------------------------ End of file ------------------------------ */
