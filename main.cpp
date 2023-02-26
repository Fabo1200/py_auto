#include <iostream>
#include <Windows.h>

int main()
{
    // Benutzer zur Eingabe der Verzögerungszeit in Millisekunden auffordern
    int delay_ms;
    std::cout << "Geben Sie die Verzoegerungszeit in Millisekunden ein(100 ist empfohlen): ";
    std::cin >> delay_ms;

    std::cout << "Halten Sie die p-Taste gedrueckt!" << std::endl;
    int times_pressed = 0;
    std::cout << "Sie koennen dieses Programm beenden, indem Sie STRG + C zusammen druecken!" << std::endl;

    while (true)
    {
        if (GetAsyncKeyState('P') & 0x8000)
        {
            // Aktuelle Position der Maus abrufen
            POINT p;
            GetCursorPos(&p);
            int x = p.x;
            int y = p.y;

            // Linke Maustaste an der aktuellen Position drücken
            INPUT input = { 0 };
            input.type = INPUT_MOUSE;
            input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
            input.mi.dx = x;
            input.mi.dy = y;
            SendInput(1, &input, sizeof(input));

            // Verzögern für die angegebene Verzögerungszeit
            Sleep(delay_ms);

            // Linke Maustaste an derselben Position loslassen
            input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
            SendInput(1, &input, sizeof(input));
            times_pressed += 1;

            // Eine Nachricht ausgeben, nachdem die linke Maustaste 50 Mal gedrückt wurde
            if (times_pressed % 50 == 0)
            {
                std::cout << "Linke Maustaste gedrueckt: " << times_pressed << " Mal!" << std::endl;
            }
        }
    }

    return 0;
}
