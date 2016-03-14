/* Вариант 5. Используя паттерн Decorator, реализовать несколько
 * представлений текстового документа (только текст, текст с логотипом
 * компании, текст с рамкой вокруг него и т.п.)
*/

#include <iostream>
#include "text.hpp"



using namespace std;

int main()
{


    Itext *ptr = new CopyrightDecorator(
                new text("myText"));


    Itext *ptr2 = new FrameDecorator(
                    new CopyrightDecorator(
                    new text("myText"))
                );

    Itext *ptr3 =
                    new FrameDecorator(
                    new text("myText"))
                ;

    Itext *ptr4 = new CopyrightDecorator(
                    new FrameDecorator (
                    new text("myText"))
                );
    ptr4->print();

    cout << "Menu:"<< endl << "1 - text" << endl << "2 - Frame" << endl << "3 - copyr" << endl;
    for (;;){
        int t;
        cin >> t;
        switch(t){
        case 1:
            ptr->print();
            break;
        case 2:
            ptr2->print();
            break;
        case 3:
            ptr3->print();
            break;
        case 4:
            ptr4->print();
            break;
        }
    }

    return 0;
}

