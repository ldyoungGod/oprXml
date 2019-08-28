#include <iostream>
#include <tinyxml/tinyxml2.h>

using namespace tinyxml2;

int main(int argc, char *argv[])
{
    XMLDocument xmlDoc;
    XMLError xmlError = xmlDoc.LoadFile("./demoCfg.xml");
    if(xmlError != XML_SUCCESS)
    {
        return -1;
    }
    XMLElement* rootElement  = xmlDoc.RootElement();
    if (rootElement == nullptr)
        return false;
    const XMLAttribute* rootAttribute = rootElement->FirstAttribute();
    std::cout<<rootAttribute->Value()<<std::endl;

    XMLElement* studentsElement = rootElement->FirstChildElement();
    if(studentsElement == nullptr)
        return false;

    XMLElement* studentElement = studentsElement->FirstChildElement();
    if(studentElement == nullptr)
        return false;
    while(studentElement)
    {
        const XMLAttribute* attribute = studentElement->FirstAttribute();
        while(attribute)
        {
            std::cout<< attribute->Value()<<"\t";
            attribute = attribute->Next();
        }
        std::cout<<std::endl;

        XMLElement* pEle = studentElement->FirstChildElement("phone");
        if(pEle)
        {
            std::cout<<"phone:"<<pEle->GetText()<<std::endl;
        }
        pEle = studentElement->FirstChildElement("address");
        if(pEle)
        {
            std::cout<<"address:"<<pEle->GetText()<<std::endl;
        }


        studentElement = studentElement->NextSiblingElement();
    }
    return 0;
}
