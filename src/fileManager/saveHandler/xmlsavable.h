#ifndef XMLSAVABLE_H
#define XMLSAVABLE_H

/**
 * @file xmlsavable.h
 */

#include "../../thirdParty/pugixml-1.8/src/pugixml.hpp"
/**
 * @brief The XMLSavable class. An object that can be saved in an XML format.
 */
class XMLSavable
{
public:
    /**
     * @brief XMLSavable The constructor (not used).
     */
    XMLSavable();
    /**
     * @brief saveXML Save this object in an XML format.
     * @param root The root xml tag that should contain this object.
     */
    virtual void saveXML(pugi::xml_node &root) = 0;

private:
};

#endif // XMLSAVABLE_H
