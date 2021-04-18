//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#ifndef PDFTRON_H_CVerificationOptions
#define PDFTRON_H_CVerificationOptions

#ifdef __cplusplus
extern "C" {
#endif

#include <pdftron/C/Common/TRN_Types.h>
#include <pdftron/C/Common/TRN_Exception.h>


struct TRN_VerificationOptions_tag;
typedef struct TRN_VerificationOptions_tag* TRN_VerificationOptions;

/* enums:  */
enum TRN_VerificationOptions_SecurityLevel {
	e_VerificationOptions_compatibility_and_archiving = 0,
	e_VerificationOptions_maximum = 1
};
enum TRN_VerificationOptions_TimeMode {
	e_VerificationOptions_signing = 0,
	e_VerificationOptions_timestamp = 1,
	e_VerificationOptions_current = 2
};

/* methods: */
TRN_API TRN_VerificationOptionsCreate(enum TRN_VerificationOptions_SecurityLevel in_level, TRN_VerificationOptions* result);
TRN_API TRN_VerificationOptionsAddTrustedCertificate(TRN_VerificationOptions self, const TRN_UChar* in_certificate_buf, const size_t in_buf_size);
TRN_API TRN_VerificationOptionsAddTrustedCertificateUString(TRN_VerificationOptions self, TRN_UString in_filepath);
TRN_API TRN_VerificationOptionsAddTrustedCertificates(TRN_VerificationOptions self, const TRN_UChar* in_P7C_binary_DER_certificates_file_data, const size_t in_size);
TRN_API TRN_VerificationOptionsEnableModificationVerification(TRN_VerificationOptions self, TRN_Bool in_on_or_off);
TRN_API TRN_VerificationOptionsEnableDigestVerification(TRN_VerificationOptions self, TRN_Bool in_on_or_off);
TRN_API TRN_VerificationOptionsEnableTrustVerification(TRN_VerificationOptions self, TRN_Bool in_on_or_off);
TRN_API TRN_VerificationOptionsSetRevocationProxyPrefix(TRN_VerificationOptions self, const TRN_UString in_str);
TRN_API TRN_VerificationOptionsEnableOnlineCRLRevocationChecking(TRN_VerificationOptions self, TRN_Bool in_on_or_off);
TRN_API TRN_VerificationOptionsEnableOnlineOCSPRevocationChecking(TRN_VerificationOptions self, TRN_Bool in_on_or_off);
TRN_API TRN_VerificationOptionsEnableOnlineRevocationChecking(TRN_VerificationOptions self, TRN_Bool in_on_or_off);

TRN_API TRN_VerificationOptionsDestroy(TRN_VerificationOptions self);


#ifdef __cplusplus
} // extern C
#endif

#endif /* PDFTRON_H_CVerificationOptions */
