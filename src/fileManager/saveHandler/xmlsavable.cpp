#include "xmlsavable.h"

XMLSavable::XMLSavable(const char *rootName)
    :rootName(rootName){

}

const char *XMLSavable::getRootName() const
{
    return rootName;
}
