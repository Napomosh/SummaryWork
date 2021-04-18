//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
// !Warning! This file is autogenerated, modify the .codegen file, not this one
// (any changes here will be wiped out during the autogen process)

#ifndef PDFTRON_H_CPDFDocGenerator
#define PDFTRON_H_CPDFDocGenerator

#ifdef __cplusplus
extern "C" {
#endif

#include <pdftron/C/Common/TRN_Types.h>
#include <pdftron/C/Common/TRN_Exception.h>


struct TRN_PDFDocGenerator_tag;
typedef struct TRN_PDFDocGenerator_tag* TRN_PDFDocGenerator;


/* methods: */
TRN_API TRN_PDFDocGeneratorGenerateBlankPaperDoc(double width, double height, double background_red, double background_green, double background_blue, TRN_PDFDoc* result);
TRN_API TRN_PDFDocGeneratorGenerateGridPaperDoc(double width, double height, double grid_spacing, double line_thickness, double red, double green, double blue, double background_red, double background_green, double background_blue, TRN_PDFDoc* result);
TRN_API TRN_PDFDocGeneratorGenerateLinedPaperDoc(double width, double height, double line_spacing, double line_thickness, double red, double green, double blue, double left_margin_distance, double left_margin_red, double left_margin_green, double left_margin_blue, double right_margin_red, double right_margin_green, double right_margin_blue, double background_red, double background_green, double background_blue, double top_margin_distance, double bottom_margin_distance, TRN_PDFDoc* result);
TRN_API TRN_PDFDocGeneratorGenerateGraphPaperDoc(double width, double height, double grid_spacing, double line_thickness, double weighted_line_thickness, int weighted_line_freq, double red, double green, double blue, double background_red, double background_green, double background_blue, TRN_PDFDoc* result);
TRN_API TRN_PDFDocGeneratorGenerateMusicPaperDoc(double width, double height, double margin, int staves, double linespace_size_pts, double line_thickness, double red, double green, double blue, double background_red, double background_green, double background_blue, TRN_PDFDoc* result);
TRN_API TRN_PDFDocGeneratorGenerateDottedPaperDoc(double width, double height, double dot_spacing, double dot_size, double red, double green, double blue, double background_red, double background_green, double background_blue, TRN_PDFDoc* result);
TRN_API TRN_PDFDocGeneratorGenerateIsometricDottedPaperDoc(double width, double height, double dot_spacing, double dot_size, double red, double green, double blue, double background_red, double background_green, double background_blue, TRN_PDFDoc* result);

#ifdef __cplusplus
} // extern C
#endif

#endif /* PDFTRON_H_CPDFDocGenerator */
