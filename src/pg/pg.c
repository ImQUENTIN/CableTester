/************************************************************************************************
* @file    pg.c
* @date    2018/8/22 19:30:29
* @brief   ParameterGroup, ??°é›†?ˆç®¡ç?
* @author  qyx
* @email   qiyuexin@yeah.net
* @Version V1.0.0
* @target  +STM32F215VE     @V1.0.0
************************************************************************************************/

//#include "target.h"
//#include "common/maths.h"

#include "pg/pg.h"

//           example
//------------------------------------------------
//  .preinit_array     :
//   {
//     PROVIDE_HIDDEN (__preinit_array_start = .);
//     KEEP (*(.preinit_array*))
//     PROVIDE_HIDDEN (__preinit_array_end = .);
//   } >FLASH
//   .init_array :
//   {
//     PROVIDE_HIDDEN (__init_array_start = .);
//     KEEP (*(SORT(.init_array.*)))
//     KEEP (*(.init_array*))
//     PROVIDE_HIDDEN (__init_array_end = .);
//   } >FLASH
//   .fini_array :
//   {
//     PROVIDE_HIDDEN (__fini_array_start = .);
//     KEEP (*(.fini_array*))
//     KEEP (*(SORT(.fini_array.*)))
//     PROVIDE_HIDDEN (__fini_array_end = .);
//   } >FLASH
//   .pg_registry :
//   {
//     PROVIDE_HIDDEN (__pg_registry_start = .);
//     KEEP (*(.pg_registry))
//     KEEP (*(SORT(.pg_registry.*)))
//     PROVIDE_HIDDEN (__pg_registry_end = .);
//   } >FLASH
//   .pg_resetdata :
//   {
//     PROVIDE_HIDDEN (__pg_resetdata_start = .);
//     KEEP (*(.pg_resetdata))
//     PROVIDE_HIDDEN (__pg_resetdata_end = .);
//   } >FLASH

const pgRegistry_t  __pg_registry_start[]     __attribute__ ((section("pg_registry_begin"),   used, aligned(4)));
const pgRegistry_t  __pg_registry_end[]       __attribute__ ((section("pg_registry_end"),     used, aligned(4)));
const uint8_t       __pg_resetdata_start[2]   __attribute__ ((section("pg_resetdata_begin"),  used, aligned(2)));
const uint8_t       __pg_resetdata_end[2]     __attribute__ ((section("pg_resetdata_end"),    used, aligned(2)));


const pgRegistry_t* pgFind(pgn_t pgn)
{
    PG_FOREACH(reg)
    {
        if (pgN(reg) == pgn)
        {
            return reg;
        }
    }
    return NULL;
}

static uint8_t *pgOffset(const pgRegistry_t* reg)
{
    return reg->address;
}

void pgResetInstance(const pgRegistry_t *reg, uint8_t *base)
{
    const uint16_t regSize = pgSize(reg);

    memset(base, 0, regSize);
    if (reg->reset.ptr >= (void*)__pg_resetdata_start && reg->reset.ptr < (void*)__pg_resetdata_end)
    {
        // pointer points to resetdata section, so it is data template
        memcpy(base, reg->reset.ptr, regSize);
    }
    else if (reg->reset.fn)
    {
        // reset function, call it
        reg->reset.fn(base, regSize);   //
    }
}

void pgReset(const pgRegistry_t* reg)
{
    pgResetInstance(reg, pgOffset(reg));
}

bool pgResetCopy(void *copy, pgn_t pgn)
{
    const pgRegistry_t *reg = pgFind(pgn);
    if (reg)
    {
        pgResetInstance(reg, copy);
        return true;
    }
    return false;
}

void pgLoad(const pgRegistry_t* reg, const void *from, int size, int version)
{
    pgResetInstance(reg, pgOffset(reg));
    // restore only matching version, keep defaults otherwise
    if (version == pgVersion(reg))
    {
        const int take = MIN(size, pgSize(reg));
        memcpy(pgOffset(reg), from, take);
    }
}

int pgStore(const pgRegistry_t* reg, void *to, int size)
{
    const int take = MIN(size, pgSize(reg));
    memcpy(to, pgOffset(reg), take);
    return take;
}

void pgResetAll(void)
{
    PG_FOREACH(reg)
    {
        pgReset(reg);
    }
}


