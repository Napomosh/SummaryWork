//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
// !Warning! This file is autogenerated, modify the .codegen file, not this one
// (any changes here will be wiped out during the autogen process)

#ifndef PDFTRON_H_CResultSnapshot
#define PDFTRON_H_CResultSnapshot

#ifdef __cplusplus
extern "C" {
#endif

#include <pdftron/C/Common/TRN_Types.h>
#include <pdftron/C/Common/TRN_Exception.h>


struct TRN_ResultSnapshot_tag;
typedef struct TRN_ResultSnapshot_tag* TRN_ResultSnapshot;


/* methods: */
TRN_API TRN_ResultSnapshotCurrentState(TRN_ResultSnapshot self, TRN_DocSnapshot* result);
TRN_API TRN_ResultSnapshotPreviousState(TRN_ResultSnapshot self, TRN_DocSnapshot* result);
TRN_API TRN_ResultSnapshotIsOk(TRN_ResultSnapshot self, TRN_Bool* result);
TRN_API TRN_ResultSnapshotIsNullTransition(TRN_ResultSnapshot self, TRN_Bool* result);

TRN_API TRN_ResultSnapshotDestroy(TRN_ResultSnapshot self);


#ifdef __cplusplus
} // extern C
#endif

#endif /* PDFTRON_H_CResultSnapshot */
