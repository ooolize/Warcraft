 ///
 /// @file    Headquarters.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-19 20:41:56
 ///
 

#ifndef __WARCRAFT_HEADQUARTERS_H__
#define __WARCRAFT_HEADQUARTERS_H__
#include "Types.h"

#include <vector>
#include <unordered_map>
using namespace std;

namespace warcraft
{

class Warrior;
class WarriorView;
class Headquarters 
{
public:
	Headquarters(Color color, size_t elements)
	: _color(color)
	, _elements(elements)
	, _buildWarriorTimes(0)
	{}

	virtual Warrior * create() = 0;
	virtual void nextWarriorType() = 0;

	template <typename Iterator>
	void setWarriorProduceOrder(Iterator beg, Iterator end) 
	{	
		for(; beg != end; ++beg) {
			_warriorProduceOrder.push_back(*beg);
		}
	}

	void setBuildWarriorTimes(size_t times) {	_buildWarriorTimes = times;	}
	size_t getBuildWarriorTimes() const {	return _buildWarriorTimes;	}
	size_t getWarriorAmounts() const {	return _warriors.size();	}
	WarriorView * getWarriorView(Warrior *);

protected:
	Color _color;
	size_t _elements;
	size_t _buildWarriorTimes;
	vector<Warrior *> _warriors;
	vector<WARRIOR_TYPE> _warriorProduceOrder;
	unordered_map<Warrior*, WarriorView *> _views;
};

class RedHeadquarters
: public Headquarters
{
public:
	RedHeadquarters(size_t elements)
	: Headquarters(RED, elements)
	, _nextWarriorIndex(0)
	{}

	Warrior * create() override;
	void nextWarriorType() override;
private:
	size_t _nextWarriorIndex;
};

class BlueHeadquarters
: public Headquarters
{
public:
	BlueHeadquarters(size_t elements)
	: Headquarters(BLUE, elements)
	, _nextWarriorIndex(0)
	{}

	Warrior * create() override;
	void nextWarriorType() override;

private:
	size_t _nextWarriorIndex;
};
}//end of namespace warcraft

#endif