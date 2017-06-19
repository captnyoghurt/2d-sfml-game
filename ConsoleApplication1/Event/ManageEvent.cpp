#include "ManageEvent.h"
#include "../Game.h"

ManageEvent::ManageEvent()
{
	createMatchingKey(IG_Action(&doNothing));
	m_keyEventLayer = 0;
	m_keyEventList.push_back(std::vector< std::pair<unsigned short, unsigned short> >(sf::Keyboard::Key::KeyCount, std::make_pair(0,0)));
}


ManageEvent::~ManageEvent()
{
}


// Return the actual key event layer
int ManageEvent::getKeyEventLayer() const
{
	return m_keyEventLayer;
}


// Return the key event list
std::vector< std::vector< std::pair<unsigned short, unsigned short> > > ManageEvent::getKeyEventList() const
{
	return m_keyEventList;
}


// Retuen the maching key event list
std::vector<IG_KeyEvent> ManageEvent::getMatchingKeyEvent() const
{
	return m_matchingKeyEvent;
}


// Modify the actual key event layer
int ManageEvent::setKeyEventLayer(const int &l)
{
	if ((unsigned)l < m_keyEventList.size())
	{
		m_keyEventLayer = l;
		return 0;
	}
	return -1;
}


// Modify a key event
int ManageEvent::setKeyEvent(int layer, int code, unsigned short matchCode, bool down)
{
	if ((unsigned)layer < m_keyEventList.size()
		&& (unsigned)code < sf::Keyboard::Key::KeyCount
		&& matchCode < m_matchingKeyEvent.size())
	{
		if(down)
			m_keyEventList.at(layer).at(code).first = matchCode;
		else
			m_keyEventList.at(layer).at(code).second = matchCode;
		return 0;
	}
	return -1;
}


// Create a matching
unsigned short ManageEvent::createMatchingKey(const IG_KeyEvent &k)
{
	m_matchingKeyEvent.push_back(k);

	return (unsigned short)(m_matchingKeyEvent.size() - 1);
}
unsigned short ManageEvent::createMatchingKey(const IG_Action &a)
{
	IG_KeyEvent igke;
	igke.setIGAction(a);

	m_matchingKeyEvent.push_back(igke);

	return (unsigned short)(m_matchingKeyEvent.size() - 1);
}


// Create the layers
int ManageEvent::createLayers(const int &l)
{
	int n = m_keyEventList.size();

	m_keyEventList.resize(l);

	if (n < l)
	{
		for (int i(n); i < l; i++)
		{
			m_keyEventList.at(i).resize(sf::Keyboard::Key::KeyCount, std::make_pair(0, 0));
		}
	}

	if (m_keyEventLayer < l)
		return 0;
	m_keyEventLayer = 0;
	return 1;
}

#include "actionFunctions.h"
// Update event
int ManageEvent::updateEvent(Game &g)
{
	sf::Event event;

	while (g.getRealWindow().pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			g.getRealWindow().close();
			return 1;
		case sf::Event::KeyPressed:
			if((unsigned)event.key.code < sf::Keyboard::Key::KeyCount)
				m_matchingKeyEvent.at(m_keyEventList.at(m_keyEventLayer).at(event.key.code).first).doAction(g);
			break;
		case sf::Event::KeyReleased:
			if ((unsigned)event.key.code < sf::Keyboard::Key::KeyCount)
				m_matchingKeyEvent.at(m_keyEventList.at(m_keyEventLayer).at(event.key.code).second).doAction(g);
			break;
		case sf::Event::Resized:
			g.getRealMap().gotUpdated();
			break;
		default:
			break;
		}
	}

	return 0;
}