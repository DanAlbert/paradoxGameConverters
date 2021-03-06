/*Copyright (c) 2016 The Paradox Game Converters Project

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.*/



#include "StateCategoryMapper.h"
#include "OSCompatibilityLayer.h"
#include "ParadoxParserUTF8.h"
#include "../Configuration.h"
#include <set>
using namespace std;



stateCategoryMapper* stateCategoryMapper::instance;


stateCategoryMapper::stateCategoryMapper()
{
	readCategoriesFromDirectory(Configuration::getHoI4Path() + "/common/state_category");
}


void stateCategoryMapper::readCategoriesFromDirectory(string directory)
{
	set<string> categoryFiles;
	Utils::GetAllFilesInFolder(directory, categoryFiles);
	for (auto file: categoryFiles)
	{
		readCategoriesFromFile(Configuration::getHoI4Path() + "/common/state_category/" + file);
	}
}


void stateCategoryMapper::readCategoriesFromFile(string file)
{
	Object* parsedFile = parser_UTF8::doParseFile(file);
	vector<Object*> StateCategoryObjs = parsedFile->getLeaves();
	vector<Object*> categoryObjs = StateCategoryObjs[0]->getLeaves();

	for (auto categoryObj: categoryObjs)
	{
		string category = categoryObj->getKey();
		string slotsString = categoryObj->getLeaf("local_building_slots");
		int slots = stoi(slotsString);
		stateCategories.insert(make_pair(slots, category));
	}
}