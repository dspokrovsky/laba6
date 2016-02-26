#ifndef TEXT_HPP
#define TEXT_HPP

#include <iostream>
#include <memory>
#include <string>

//создание абстрактного класса LCD(lowest common denominator)
class Itext
{
public:
    virtual void print() = 0;
    virtual ~Itext(){};

};

//определение основного класса, который наследует LCD
class text: public Itext{
public:
    text(std::string k):text_(k){}

    virtual void print(){
        std::cout << text_;
    }
private:
    std::string text_;
};




//базовый класс второго уровня (Decorator) для поддержки дополнительных декорирующих классов.
class Decorator :public Itext{
    std::shared_ptr<Itext> m_component;
public:
    Decorator(Itext* component): m_component(component) {}
    virtual void print() {
        m_component->print();
    }
};
//дополнительная функциональность
class CopyrightDecorator: public Decorator
{
  public:
    CopyrightDecorator(Itext *w): Decorator(w){}

    /*virtual*/
    void print()
    {
        // 7. Делегирование базовому классу и
        Decorator::print();
        // 7. реализация дополнительной функциональности
        std::cout << "   (c)Copyright" << '\n';
    }
};

//дополнительная функциональность
class FrameDecorator: public Decorator
{
  public:
    FrameDecorator(Itext *w): Decorator(w){}

    /*virtual*/
    void print()
    {
        std::cout << "**************"<<std::endl;
        Decorator::print();
        std::cout <<std::endl << "**************"<<std::endl;
    }
};
#endif // TEXT_HPP
