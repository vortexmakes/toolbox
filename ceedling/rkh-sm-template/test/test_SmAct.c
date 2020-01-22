/**
 *  \file       test_SmACt.c
 *  \brief      Unit test for state machine module.
 */

/* -------------------------- Development history -------------------------- */
/*
 */

/* -------------------------------- Authors -------------------------------- */
/*
 *  LeFr  Leandro Francucci lf@vortexmakes.com
 */

/* --------------------------------- Notes --------------------------------- */
/* ----------------------------- Include files ----------------------------- */
#include "unity.h"
#include "Sm.h"
#include "SmAct.h"
#include "rkhfwk_cast.h"
#include "Mock_rkhtmr.h"
#include "Mock_rkhtrc_record.h"
#include "Mock_rkhsma.h"
#include "Mock_rkhassert.h"

/* ----------------------------- Local macros ------------------------------ */
/* ------------------------------- Constants ------------------------------- */
/* Instantiate states and pseudostates */
/* For example: */
/* RKHROM RKH_SBSC_T StateA, StateB; */
/* RKHROM RKH_SCMP_T Composite; */
/* RKHROM RKH_SCHOICE_T C0; */
/* RKHROM RKH_FINAL_T Final; */

/* ---------------------------- Local data types --------------------------- */
/* ---------------------------- Global variables --------------------------- */
/* ---------------------------- Local variables ---------------------------- */
/* Instantiate active object */
/* RKH_SMA_CREATE(CommMgr, commMgr, 0, HCAL, NULL, CommMgr_ToIdleExt0, NULL); */
/* RKH_SMA_DEF_PTR(commMgr); */
/* static CommMgr *me; */

/* If you use virtual functions, you have to instantiate the virtual table, */
/* because rkhsma module is mocked */
/* For example: */
/* const RKHSmaVtbl rkhSmaVtbl =  */
/* { */
/*     rkh_sma_activate, */
/*     rkh_sma_dispatch, */
/*     rkh_sma_post_fifo, */
/*     rkh_sma_post_lifo */
/* }; */

/* ----------------------- Local function prototypes ----------------------- */
/* ---------------------------- Local functions ---------------------------- */
/* If you use RKH's assertion, you can use this callback */
/* For example: */
/* static void */
/* MockAssertCallback(const char* const file, int line, int cmock_num_calls) */
/* { */
/*     TEST_PASS(); */
/* } */

/* ---------------------------- Global functions --------------------------- */
void
setUp(void)
{
    /* Initialize me pointer */
    /* For example: */
    /* me = RKH_DOWNCAST(CommMgr, commMgr); */
}

void
tearDown(void)
{
}

void
test_Something(void)
{
}

/* ------------------------------ End of file ------------------------------ */
