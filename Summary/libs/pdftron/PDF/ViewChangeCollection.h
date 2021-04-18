#ifndef PDFTRON_H_CPPPDFViewChangeCollection
#define PDFTRON_H_CPPPDFViewChangeCollection

#include <pdftron/C/PDF/TRN_ViewChangeCollection.h>

namespace pdftron {
	namespace PDF {
		
class ViewChangeCollection
{
public:
	ViewChangeCollection();
	~ViewChangeCollection();
	ViewChangeCollection(const ViewChangeCollection& view_change);
	ViewChangeCollection& operator=(const ViewChangeCollection& view_change);

	void Destroy();

	//for xamarin use only
	static ViewChangeCollection* CreateInternal(ptrdiff_t impl);
	ptrdiff_t GetHandleInternal();
		
#ifndef SWIGHIDDEN
	ViewChangeCollection(TRN_ViewChangeCollection impl);
	TRN_ViewChangeCollection mp_collection;
#endif
};

	}
}

#include<pdftron/Impl/ViewChangeCollection.inl>

#endif