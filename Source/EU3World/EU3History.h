#ifndef EU3HISTORY_H_
#define EU3HISTORY_H_


#include "..\Date.h"
#include "..\CK2World\CK2History.h"
#include "EU3Ruler.h"
#include <fstream>



class EU3History {
	public:
		void			init(CK2History*);
		void			initHeir(EU3Ruler*);
		void			output(FILE*);
		EU3Ruler*	getMonarch();
	private:
		date			when;
		EU3Ruler*	monarch;
		EU3Ruler*	heir;
};


#endif // EU3HISTORY_H_