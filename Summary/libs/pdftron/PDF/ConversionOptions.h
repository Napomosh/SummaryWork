// This file is autogenerated: please see the codegen template "Options"
#ifndef PDFTRON_H_CPPPDFConversionOptions
#define PDFTRON_H_CPPPDFConversionOptions

#include <pdftron/SDF/ObjSet.h>

namespace pdftron{ namespace PDF{ 

class ConversionOptions
{
public:
	ConversionOptions();
	ConversionOptions(const UString& value);

	virtual ~ConversionOptions();

	// @cond PRIVATE_DOC
	#ifndef SWIGHIDDEN
	SDF::Obj& GetInternalObj();

protected:
	SDF::ObjSet m_obj_set;
	SDF::Obj m_dict;
	#endif
};

}
}

#include "pdftron/Impl/ConversionOptions.inl"
#endif // PDFTRON_H_CPPPDFConversionOptions
