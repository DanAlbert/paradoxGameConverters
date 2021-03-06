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



#include "HOI4Version.h"
#include "Log.h"



HOI4Version::HOI4Version()
{
	first		= 0;
	second	= 0;
	third		= 0;
}


HOI4Version::HOI4Version(Object* obj)
{
	vector<Object*> numberObj;
	numberObj = obj->getValue("first");
	if (numberObj.size() > 0)
	{
		first = stoi(numberObj[0]->getLeaf());
	}

	numberObj = obj->getValue("second");
	if (numberObj.size() > 0)
	{
		second = stoi(numberObj[0]->getLeaf());
	}

	numberObj = obj->getValue("third");
	if (numberObj.size() > 0)
	{
		third = stoi(numberObj[0]->getLeaf());
	}
}


HOI4Version::HOI4Version(string version)
{
	int dot = version.find_first_of('.');
	first = stoi(version.substr(0, dot));

	version = version.substr(dot + 1, version.size());
	dot = version.find_first_of('.');
	second = stoi(version.substr(0, dot));

	version = version.substr(dot + 1, version.size());
	dot = version.find_first_of('.');
	third = stoi(version.substr(0, dot));
}


bool HOI4Version::operator >= (HOI4Version& rhs) const
{
	if (first > rhs.first)
	{
		return true;
	}
	else if ((first == rhs.first) && (second > rhs.second))
	{
		return true;
	}
	else if ((first == rhs.first) && (second == rhs.second) && (third > rhs.third))
	{
		return true;
	}
	else if ((first == rhs.first) && (second == rhs.second) && (third == rhs.third))
	{
		return true;
	}
	else
	{
		return false;
	}
}


ostream& operator << (ostream& out, HOI4Version& version)
{
	out << version.first << '.' << version.second << '.' << version.third;

	return out;
}