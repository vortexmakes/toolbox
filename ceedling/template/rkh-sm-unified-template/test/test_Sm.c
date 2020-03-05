/**
 *  \file       test_Sm.c
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
#include "rkhfwk_cast.h"
#include "Mock_rkhtmr.h"
#include "Mock_rkhtrc_record.h"
#include "Mock_rkhsma.h"
#include "Mock_rkhassert.h"

/* ----------------------------- Local macros ------------------------------ */
/* ------------------------------- Constants ------------------------------- */
/* ---------------------------- Local data types --------------------------- */
/* ---------------------------- Global variables --------------------------- */
/* ---------------------------- Local variables ---------------------------- */
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
