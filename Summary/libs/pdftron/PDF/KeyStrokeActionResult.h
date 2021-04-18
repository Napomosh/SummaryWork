#ifndef PDFTRON_H_CPPPDFKeyStrokeActionResult
#define PDFTRON_H_CPPPDFKeyStrokeActionResult

#include <pdftron/C/PDF/TRN_Action.h>
#include <pdftron/SDF/Obj.h>

namespace pdftron {
	namespace PDF {

class KeyStrokeActionResult
{
public:
	~KeyStrokeActionResult();
	bool IsValid();
	UString GetText();
	KeyStrokeActionResult(const KeyStrokeActionResult& action_result);
	KeyStrokeActionResult& operator=(const KeyStrokeActionResult& action_result);

	void Destroy();
#ifndef SWIGHIDDEN
    KeyStrokeActionResult();
	KeyStrokeActionResult(TRN_KeyStrokeActionResult impl);
	TRN_KeyStrokeActionResult mp_result;
#endif 
};
	}
}

#include<pdftron/Impl/KeyStrokeActionResult.inl>

#endif