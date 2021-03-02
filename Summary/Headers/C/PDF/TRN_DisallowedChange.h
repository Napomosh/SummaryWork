//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
// !Warning! This file is autogenerated, modify the .codegen file, not this one
// (any changes here will be wiped out during the autogen process)

#ifndef PDFTRON_H_CDisallowedChange
#define PDFTRON_H_CDisallowedChange

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>
#include <C/Common/TRN_Exception.h>


struct TRN_DisallowedChange_tag;
typedef struct TRN_DisallowedChange_tag* TRN_DisallowedChange;

/* enums:  */
enum TRN_DisallowedChange_Type {
	e_DisallowedChange_form_filled = 0,
	e_DisallowedChange_digital_signature_signed = 1,
	e_DisallowedChange_page_template_instantiated = 2,
	e_DisallowedChange_annotation_created_or_updated_or_deleted = 3,
	e_DisallowedChange_other = 4,
	e_DisallowedChange_unknown = 5
};

/* methods: */
TRN_API TRN_DisallowedChangeGetObjNum(TRN_DisallowedChange self, TRN_UInt32* result);
TRN_API TRN_DisallowedChangeGetType(TRN_DisallowedChange self, enum TRN_DisallowedChange_Type* result);
TRN_API TRN_DisallowedChangeGetTypeAsString(TRN_DisallowedChange self, TRN_UString* result);

TRN_API TRN_DisallowedChangeDestroy(TRN_DisallowedChange self);


#ifdef __cplusplus
} // extern C
#endif

#endif /* PDFTRON_H_CDisallowedChange */
