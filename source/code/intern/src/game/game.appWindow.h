#pragma once

#include <SFML/Graphics.hpp>
#include <tinyxml2.h>


namespace Game
{
    class CApplicationWindow
    {
    public:
        static CApplicationWindow& GetInstance()
        {
            static CApplicationWindow instance;
            return instance;
        };

        CApplicationWindow(const CApplicationWindow&) = delete;
        CApplicationWindow& operator = (const CApplicationWindow&) = delete;


    private:
        CApplicationWindow()
        {};

    public:
        sf::RenderWindow m_AppWindow;

    public:
        void OnCreate() {
            m_AppWindow.create(sf::VideoMode(1900, 896), "Bilal Alnaani Application");
        };

    };
}