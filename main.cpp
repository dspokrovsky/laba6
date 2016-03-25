/* Вариант 5. Используя паттерн Decorator, реализовать несколько
 * представлений текстового документа (только текст, текст с логотипом
 * компании, текст с рамкой вокруг него и т.п.)
*/

#include <iostream>
#include "text.hpp"



using namespace std;

int main()
{


    Itext *ptr = new text("myText");


    Itext *ptr1 = new CopyrightDecorator(
                new text("myText"),"MYCOPYRIGHT");


    Itext *ptr2 = new FrameDecorator(
                    new CopyrightDecorator(
                    new text("myText"),"POKROVSKY")
                );

    Itext *ptr3 =
                    new FrameDecorator(
                    new text("myText"))
                ;

    Itext *ptr4 = new CopyrightDecorator(
                    new FrameDecorator (
                    new text("myText")),"COPY"
                );

    Itext *ptr5 = new LogoDecorator(
                    new text("myText"),"LOGO");
    ptr5->print();

    cout << "Menu:"<< endl << "1 - Text" << endl << "2 - Frame" << endl << "3 - Copiright\n"<<"4 - Copyright + Frame\n"<<"5- Frame + Copiright\n" << endl <<"6 - Logo"<<endl;
    for (;;){        
        int t;
        cin >> t;
        switch(t){
        case 1:
            ptr->print();
            break;
        case 2:
            ptr3->print();
            break;
        case 3:
            ptr1->print();
            break;
        case 4:
            ptr4->print();
            break;
        case 5:
            ptr2->print();
            break;
        case 6:
            ptr5->print();
            break;
        }
    }

    return 0;
}

