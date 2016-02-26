/* Вариант 5. Используя паттерн Decorator, реализовать несколько
 * представлений текстового документа (только текст, текст с логотипом
 * компании, текст с рамкой вокруг него и т.п.)
*/

#include <iostream>
#include "text.hpp"




int main()
{
    Itext *ptr = new CopyrightDecorator(
                new text("myText"));
    ptr->print();

    Itext *ptr2 = new FrameDecorator(
                    new CopyrightDecorator(
                    new text("myText"))
                );
    ptr2->print();
    Itext *ptr3 =
                    new FrameDecorator(
                    new text("myText"))
                ;
    ptr3->print();

    Itext *ptr4 = new CopyrightDecorator(
                    new FrameDecorator (
                    new text("myText"))
                );
    ptr4->print();
    return 0;
}

