// This file is autogenerated: please see the codegen template "Options"
#ifndef PDFTRON_H_CPPPDFCADConvertOptions
#define PDFTRON_H_CPPPDFCADConvertOptions

#include <pdftron/PDF/OptionsBase.h>

namespace pdftron{ namespace PDF{ 

class CADConvertOptions
{
public:
	CADConvertOptions();
	~CADConvertOptions();

	
	/**
	* Gets the value AllowThinLines from the options object
	* Sets drawing line weights to zero
	* @ return a bool, the current value for AllowThinLines.
	*/
	bool GetAllowThinLines();

	/**
	* Sets the value for AllowThinLines in the options object
	* Sets drawing line weights to zero
	* @param value: the new value for AllowThinLines
	* @return this object, for call chaining
	*/
	CADConvertOptions& SetAllowThinLines(bool value);

	
	/**
	* Gets the value AutoRotate from the options object
	* Maps the orientation to the sheet dimensions
	* @ return a bool, the current value for AutoRotate.
	*/
	bool GetAutoRotate();

	/**
	* Sets the value for AutoRotate in the options object
	* Maps the orientation to the sheet dimensions
	* @param value: the new value for AutoRotate
	* @return this object, for call chaining
	*/
	CADConvertOptions& SetAutoRotate(bool value);

	
	/**
	* Gets the value BackgroundColor from the options object
	* Sets background color for cad conversion (display palette may be adjusted to contrast the chosen background color)
	* @ return a ColorPt, the current value for BackgroundColor.
	*/
	ColorPt GetBackgroundColor();

	/**
	* Sets the value for BackgroundColor in the options object
	* Sets background color for cad conversion (display palette may be adjusted to contrast the chosen background color)
	* @param value: the new value for BackgroundColor
	* @return this object, for call chaining
	*/
	CADConvertOptions& SetBackgroundColor(ColorPt value);


	/**
	* Sets the value for ColorMode in the options object
	* Sets the color palette used by the drawing export. Possible values are Mono (i.e., monochrome) and Gray (i.e., grayscale), otherwise drawing's original palette is used
	* @param value: the new value for ColorMode
	* @return this object, for call chaining
	*/
	CADConvertOptions& SetColorMode(const UString& value);

	
	/**
	* Gets the value PageHeight from the options object
	* The height of the output pdf, in millimeters
	* @ return a double, the current value for PageHeight.
	*/
	double GetPageHeight();

	/**
	* Sets the value for PageHeight in the options object
	* The height of the output pdf, in millimeters
	* @param value: the new value for PageHeight
	* @return this object, for call chaining
	*/
	CADConvertOptions& SetPageHeight(double value);

	
	/**
	* Gets the value PageWidth from the options object
	* The width of the output pdf, in millimeters
	* @ return a double, the current value for PageWidth.
	*/
	double GetPageWidth();

	/**
	* Sets the value for PageWidth in the options object
	* The width of the output pdf, in millimeters
	* @param value: the new value for PageWidth
	* @return this object, for call chaining
	*/
	CADConvertOptions& SetPageWidth(double value);

	
	/**
	* Gets the value RasterDPI from the options object
	* Rasterization dpi used when rendering 3D content. Currently only applies to .rvt conversions
	* @ return a double, the current value for RasterDPI.
	*/
	double GetRasterDPI();

	/**
	* Sets the value for RasterDPI in the options object
	* Rasterization dpi used when rendering 3D content. Currently only applies to .rvt conversions
	* @param value: the new value for RasterDPI
	* @return this object, for call chaining
	*/
	CADConvertOptions& SetRasterDPI(double value);

	

	/**
	* Adds the  to the Sheets array
	* The list of sheets to be converted -- only applies to .rvt conversions
	* @param value: the new  to be added to Sheets
	* @return this object, for call chaining
	*/
	CADConvertOptions& AddSheets(const UString& value);

	
	// @cond PRIVATE_DOC
	#ifndef SWIGHIDDEN
	SDF::Obj& GetInternalObj();

private:
	
	SDF::ObjSet m_obj_set;
	SDF::Obj m_dict;
	#endif
	// @endcond
};

}
}

#include "pdftron/Impl/CADConvertOptions.inl"
#endif // PDFTRON_H_CPPPDFCADConvertOptions
